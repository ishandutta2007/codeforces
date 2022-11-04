#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,m,d[N],f[N];
vector<int>e[N];
bool vst[N];

void bfs() {
	rep(i,1,n) d[i]=n+1; d[1]=0;
	queue<int>q; q.push(1);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(auto v:e[u]) if(d[v]==n+1) d[v]=d[u]+1,q.push(v);
	}
}
void dfs(int u) {
	f[u]=d[u], vst[u]=1;
	for(auto v:e[u]) {
		if(d[u]<d[v]) {
			if(!vst[v]) dfs(v);
			f[u]=min(f[u],f[v]);
		} else f[u]=min(f[u],d[v]);
	}
}

int main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) e[i].clear(),vst[i]=0;
		rep(i,1,m) {
			int u=read(), v=read();
			e[u].push_back(v);
		}
		bfs();
		rep(i,1,n) if(!vst[i]) dfs(i);
		rep(i,1,n) printf("%d ",f[i]); puts("");
	}
	return 0;
}