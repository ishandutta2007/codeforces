#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10;
int n,m,x,a[N],s;
int dele[N],delv[N];
struct node{
	int v,id;
	bool operator < (const node &x) const {
		return v!=x.v?v<x.v:id<x.id;
	}
};set<node> g[N];
set<node> q;
int lst[N];
int merge(int u,int v,int id){
	dele[id]=1;if(g[u].size()<g[v].size())swap(u,v);delv[v]=1;
	for(auto x:g[v]){
		if(dele[x.id]||delv[x.v])continue;
		int w=x.v;//(v,w) -> (u,w), (w,v) -> (w,u)
		g[w].erase(g[w].find((node){v,x.id}));g[w].insert((node){u,x.id});
		g[u].insert((node){w,x.id});
	}return u;
}
int head[N],to[N<<1],val[N<<1],nxt[N<<1],cnt;
void add(int u,int v,int w){
	to[++cnt]=v,val[cnt]=w,nxt[cnt]=head[u],head[u]=cnt;
}int vis[N];
void dfs(int u){
	vis[u]=1;go(u){
		int v=to[i],I=val[i];if(vis[v])continue;
		g[u].insert((node){v,I});
		g[v].insert((node){u,I});
		dfs(v);
	}
}
signed main(){
	n=read(),m=read(),x=read();For(i,1,n)s+=a[i]=read(),q.insert((node){a[i],i});
	if(s<(n-1)*x)return puts("NO"),0;puts("YES");
	For(i,1,m){
		int u=read(),v=read();
		add(u,v,i),add(v,u,i);
//		g[u].push_back((node){v,i});
//		g[v].push_back((node){u,i});
	}dfs(1);int T=n-1;while(T--){
//		for(auto v:q)printf("a[%d] = %d\n",v.id,v.v);
		int u=(*--q.end()).id;q.erase(--q.end());
//		printf("erase a[%d] = %d\n",u,a[u]);
		while(1){
			assert(g[u].size());
			auto x=*--g[u].end();
			g[u].erase(--g[u].end());
			if(dele[x.id]||delv[x.v])continue;
			int U=merge(u,x.v,x.id);
//			printf("erase a[%d] = %d\n",x.v,a[x.v]);
			q.erase(q.find((node){a[x.v],x.v}));
			a[U]=a[u]+a[x.v]-::x;
//			printf("insert a[%d] = %d\n",U,a[U]);
			q.insert((node){a[U],U});
			printf("%d\n",x.id);
			break;
		}
	}
	return 0;
}