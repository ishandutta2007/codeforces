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

#define MOD 998244353

int md(int x){if(x>=MOD)x-=MOD;return x;}

int p2(int e){
	int r=1;
	fore(_,0,e){
		r=md(r+r);
	}
	return r;
}

int n,m;
vector<int> g[300005];
int q[2];
int c[300005];

bool dfs(int x){
	q[c[x]]++;
	for(int y:g[x]){
		if(c[y]<0){
			c[y]=c[x]^1;
			if(!dfs(y))return false;
		}
		if(c[y]==c[x])return false;
	}
	return true;
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d",&n,&m);
		fore(_,0,m){
			int x,y;
			scanf("%d%d",&x,&y);x--;y--;
			g[x].pb(y);g[y].pb(x);
		}
		fore(i,0,n)c[i]=-1;
		ll r=1;bool can=true;
		fore(i,0,n)if(c[i]<0){
			c[i]=q[0]=q[1]=0;
			if(!dfs(i)){can=false;break;}
			r=r*md(p2(q[0])+p2(q[1]))%MOD;
		}
		if(!can)puts("0");
		else printf("%lld\n",r);
		fore(i,0,n)g[i].clear();
	}
	return 0;
}