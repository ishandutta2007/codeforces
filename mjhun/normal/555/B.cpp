#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#define mp make_pair
#define fst first
#define snd second
#define ll long long
using namespace std;

int n,m;
pair<pair<ll,ll>,int> v[200005];
multiset<pair<ll,int> > w;
ll ls[200005];
ll rs[200005];
int z[200005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%I64d%I64d",ls+i,rs+i);
	}
	for(int i=0;i<m;++i){
		ll a;
		scanf("%I64d",&a);
		w.insert(mp(a,i));	
	}
	for(int i=0;i<n-1;++i){
		v[i]=mp(mp(rs[i+1]-ls[i],ls[i+1]-rs[i]),i);
	}
	sort(v,v+(n-1));
	bool r=true;
	for(int i=0;r&&i<n-1;++i){
		ll s=v[i].fst.snd,e=v[i].fst.fst;
		multiset<pair<ll,int> >::iterator it=w.lower_bound(mp(s,0));
		if(it==w.end()||it->fst>e){
			r=false;
		}
		else{
			z[v[i].snd]=it->snd;
			w.erase(it);
		}
	}
	if(r){
		puts("Yes");
		for(int i=0;i<n-1;++i){
			if(i)putchar(' ');
			printf("%d",z[i]+1);
		}
		putchar('\n');
	}
	else{
		puts("No");
	}
	return 0;
}