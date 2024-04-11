#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> g[200005];
int n;
ll s[200005],z[200005];
ll rr;

void dfs0(int x, int p){
	s[x]=1;z[x]=0;
	for(int y:g[x]){
		if(y==p)continue;
		dfs0(y,x);
		s[x]+=s[y];
		z[x]+=z[y];
	}
	z[x]+=s[x];
}

void dfs1(int x, int p, ll w){
	rr=max(rr,n+z[x]-s[x]+w);
	for(int y:g[x]){
		if(y==p)continue;
		ll nw=(n-s[y])+(z[x]-s[x]-z[y])+w;
		dfs1(y,x,nw);
	}
}

int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs0(0,-1);
	dfs1(0,-1,0);
	printf("%lld\n",rr);
	return 0;
}