#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int n;
int st[17][1<<17];
pair<int,int> v[1<<17];
vector<int> w[1<<17];
int x[1<<17];
int nx;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",&st[0][i]);
		v[i]=mp(st[0][i],i);
	}
	sort(v,v+n);
	fore(i,0,n){
		if(i==0||v[i].fst!=v[i-1].fst)x[nx++]=v[i].fst;
		w[nx-1].pb(v[i].snd);
	}
	for(int k=1;(1<<k)<=n;++k){
		for(int i=0;i+(1<<k)<=n;++i){
			st[k][i]=gcd(st[k-1][i],st[k-1][i+(1<<(k-1))]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);s--;
		int k=31-__builtin_clz(e-s);
		int g=gcd(st[k][s],st[k][e-(1<<k)]);
		int l=lower_bound(x,x+nx,g)-x;
		if(x[l]==g){
			printf("%d\n",e-s-(lower_bound(w[l].begin(),w[l].end(),e)-lower_bound(w[l].begin(),w[l].end(),s)));
		}
		else {
			printf("%d\n",e-s);
		}
	}
	return 0;
}