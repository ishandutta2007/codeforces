#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;
int n,h[N],son[N],g[N<<1],*f[N],ans[N],*cur=g;
vi e[N];

void dfs1(int u,int fa) {
	for(auto v:e[u]) if(v!=fa) {
		dfs1(v,u);
		if(h[v]>=h[son[u]]) son[u]=v, h[u]=h[v]+1;
	}
}
void dfs2(int u,int fa) {
	if(son[u]) {
		f[son[u]]=f[u]+1, dfs2(son[u],u), ans[u]=ans[son[u]]+1;
	}
	int mh=0;
	for(auto v:e[u]) if(v!=fa&&v!=son[u]) {
		f[v]=cur, cur+=h[v]+1;
		dfs2(v,u);
		rep(i,0,h[v]) f[u][i+1]+=f[v][i];
		mh=max(mh,h[v]+1);
	}
	f[u][0]=1;
	rep(i,0,mh)
		if(f[u][i]>f[u][ans[u]]||f[u][i]==f[u][ans[u]]&&i<ans[u]) ans[u]=i;
}

int main() {
	n=read();
	rep(i,2,n) {
		int u=read(), v=read();
		e[u].emplace_back(v), e[v].emplace_back(u);
	}
	dfs1(1,0);
	f[1]=cur, cur+=h[1]+1; dfs2(1,0);
	rep(i,1,n) printf("%d\n",ans[i]);
	return 0;
}