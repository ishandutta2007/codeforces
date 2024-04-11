#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define bp __builtin_parity
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

const int N=2009;
int n,e[N][N],m,sz[N];

int id[N];
int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}

struct edge {int u,v,w;} ed[N*N];
bool cmp(const edge &x,const edge &y) {return x.w>y.w;}
vi t[N];

void dfs(int u,int fa) {
	sz[u]=1;
	for(auto v:t[u]) if(v!=fa) {
		dfs(v,u);
		sz[u]+=sz[v];
	}
	if(fa) {
		printf("%lld %lld %lld\n",u,fa,(e[fa][fa]-e[fa][u])/sz[u]);
	}
}

signed main() {
	n=read();
	rep(i,1,n) rep(j,1,i) e[i][j]=e[j][i]=read();
	rep(i,1,n) rep(j,1,i) ed[++m]=(edge){i,j,e[i][j]};
	sort(ed+1,ed+m+1,cmp);
	rep(i,1,n) id[i]=i;
	rep(i,1,m) {
		int x=ed[i].u, y=ed[i].v;
		if(find(x)==find(y)) continue;
		t[x].eb(y), t[y].eb(x);
		id[find(x)]=find(y);
	}
	dfs(1,0);
	return 0;
}