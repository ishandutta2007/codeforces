#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,m,deg[N];
vector<int> g[N];
int fa[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool merge(int x,int y){
	x=get(x),y=get(y);if(x==y)return 0;
	fa[x]=y;return 1;
}map<int,int> mp[N];
int stk[N],tp,ok[N],used[N];
signed main(){
	n=read(),m=read();For(i,1,n)fa[i]=i;
	For(i,1,m){
		int u=read(),v=read();
		mp[u][v]=mp[v][u]=1;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++,deg[v]++;
	}int mn=n+1,id=0;For(i,1,n)if(deg[i]<mn)mn=deg[i],id=i;
	for(int v:g[id])stk[++tp]=v,ok[v]=1;
	For(i,1,n)if(!ok[i])merge(id,i);
	int ans=tp;
	For(i,1,tp){
		int u=stk[i];
		for(int v:g[u])ok[v]=i;
		For(v,1,n)if(ok[v]!=i)if(merge(u,v)){ans--;}
	}cout<<ans<<endl;
	return 0;
}