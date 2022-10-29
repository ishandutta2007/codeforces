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

int ex[200005],ey[200005],r[200005];
vector<int> g[200005];
bool vis[200005];
int n,m,s[200005];

void dfs(int x, int p=-1){
	vis[x]=true;
	for(int i:g[x]){
		int y=ex[i]^ey[i]^x;
		if(vis[y])continue;
		dfs(y,i);
		s[x]+=s[y];
	}
	if(s[x]){
		if(x==ex[p])r[p]=-s[x];
		else r[p]=s[x];
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",s+i);
	scanf("%d",&m);
	fore(i,0,m){
		scanf("%d %d",ex+i,ey+i);ex[i]--;ey[i]--;
		g[ex[i]].pb(i);g[ey[i]].pb(i);
	}
	int t=0;
	fore(i,0,n)t+=s[i];
	if(t){puts("Impossible");return 0;}
	puts("Possible");
	dfs(0);
	fore(i,0,m)printf("%d\n",r[i]);
	return 0;
}