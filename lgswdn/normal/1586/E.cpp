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

const int N=3e5+9;

int n,m,q,fa[N],d[N],cnt[N],f[N],rans,c[N];
vi ge[N],e[N],ans[N];
bool vst[N];

void dfs(int u) {
	vst[u]=1;
	for(auto v:ge[u]) if(!vst[v]) {
		e[u].emplace_back(v), fa[v]=u, d[v]=d[u]+1;
		dfs(v); 
	}
}

void query(int u,int v,int id) {
	int u0=u,v0=v,lca=0;
	if(d[u]<d[v]) swap(u,v);
	while(d[u]>d[v]) c[u]++, u=fa[u];
	while(u!=v) c[u]++, c[v]++, u=fa[u], v=fa[v];
	lca=u, u=u0, v=v0;
	while(u!=lca) ans[id].emplace_back(u), u=fa[u]; ans[id].emplace_back(lca);
	stack<int>st; while(v!=lca) st.push(v), v=fa[v]; while(!st.empty()) ans[id].emplace_back(st.top()), st.pop(); 
}

void dfs2(int u) {
	for(auto v:e[u]) {
		dfs2(v); f[u]+=f[v];
	}
	rans+=f[u]/2; f[u]%=2;
	if(c[u]%2) f[u]=1;
	else rans+=f[u], f[u]=0;
}

int main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read();
		ge[u].emplace_back(v), ge[v].emplace_back(u);
	}
	d[1]=1; dfs(1);
	q=read();
	rep(i,1,q) {
		int u=read(), v=read();
		query(u,v,i);
	}
	bool flag=1;
	rep(i,1,n) if(c[i]%2==1) flag=0;
	//rep(i,1,n) cout<<c[i]<<" "; puts("");
	if(flag) {
		puts("YES");
		rep(i,1,q) {
			int p=ans[i].size(); printf("%d\n",p);
			for(auto x:ans[i]) printf("%d ",x); puts("");
		}
	} else {
		puts("NO");
		dfs2(1);
		printf("%d\n",rans+f[1]);
	}
	return 0;
}