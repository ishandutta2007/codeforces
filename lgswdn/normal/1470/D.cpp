#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=3e5+9;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,m,pos[N],dfn[N],tick,tag[N];
vector<int>e[N];

void dfs(int u) {
	dfn[u]=++tick,pos[tick]=u;
	for(auto v:e[u]) if(!dfn[v]) dfs(v);
}

int main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) tag[i]=dfn[i]=0, e[i].clear();
		tick=0;
		rep(i,1,m) {
			int u=read(), v=read();
			e[u].push_back(v), e[v].push_back(u);
		}
		dfs(1);
		bool flag=0;
		rep(i,1,n) if(!dfn[i]) {flag=1; break;}
		if(flag) {puts("NO"); continue;}
		puts("YES");
		vector<int>ans;
		rep(i,1,n) {
			int u=pos[i];
			tag[u]=1;
			for(auto v:e[u]) tag[u]&=!tag[v];
			if(tag[u]) ans.push_back(u);
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d ",x);
		puts("");
	}
	return 0;
}