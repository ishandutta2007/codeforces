#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

int n,m;
map<int,vector<int> > w;
set<int> p;
int r[200005];
int rr;
int c[2];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		w[a].pb(i);
	}
	for(auto it=w.begin();it!=w.end();++it){
		if(c[it->fst%2]<n/2){
			r[it->snd[0]]=it->fst;
			c[it->fst%2]++;
		}
		else p.insert(it->snd[0]);
		fore(i,1,it->snd.size())p.insert(it->snd[i]);
	}
	rr=p.size();
	int k=0;
	fore(_,c[0],n/2){
		k+=2;
		while(w.count(k))k+=2;
		r[*p.begin()]=k;
		p.erase(p.begin());
	}
	if(k>m)perdi();
	k=-1;
	fore(_,c[1],n/2){
		k+=2;
		while(w.count(k))k+=2;
		r[*p.begin()]=k;
		p.erase(p.begin());
	}
	if(k>m)perdi();
	assert(p.empty());
	printf("%d\n",rr);
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r[i]);
	}
	puts("");
	return 0;
}