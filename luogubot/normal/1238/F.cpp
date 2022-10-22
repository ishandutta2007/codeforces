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
const int N=3e5+10;
int n;vector<int> g[N];
int f[N],deg[N],ans;
bool cmp(int u,int v){return f[u]>f[v];}
void dfs(int u,int fa){
//	printf("%d -> %d\n",fa,u);
	sort(g[u].begin(),g[u].end());
	if(fa)g[u].erase(lower_bound(g[u].begin(),g[u].end(),fa));
	f[u]=deg[u]+1;for(int v:g[u])dfs(v,u),f[u]=max(f[u],f[v]+deg[u]-1);
	ans=max(ans,f[u]);if(g[u].size()>1)
		sort(g[u].begin(),g[u].end(),cmp),ans=max(ans,f[g[u][0]]+f[g[u][1]]+deg[u]-3);
//	printf("f[%d] = %d\n",u,f[u]);
}
signed main(){
	int T=read();while(T--){
		n=read();For(u,1,n)deg[u]=f[u]=0,g[u].clear();ans=0;
		For(i,2,n){
			int u=read(),v=read();
			g[u].push_back(v),g[v].push_back(u);
			deg[u]++,deg[v]++;
		}dfs(1,0),cout<<ans<<endl;
	}
	return 0;
}