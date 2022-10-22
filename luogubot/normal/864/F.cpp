#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int short
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=3e3+10,LG=12;
int n,m,q,f[N][LG][N];//f[t][i][u]:tu2^i 
vector<int> g[N];int vis[N],U[N],V[N];
void dfs(int u){vis[u]=1;for(int v:g[u])if(!vis[v])dfs(v);}
void init(int f[LG][N],int t){
	For(u,1,n+1)f[0][u]=n+1;
	For(i,1,m){int u=U[i],v=V[i];if(vis[u]&&vis[v])f[0][u]=min(f[0][u],v);}
	f[0][t]=n+1;For(j,1,LG-1)For(i,1,n+1)f[j][i]=f[j-1][f[j-1][i]];
}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),m=read();signed q;cin>>q;
	For(i,1,m){int u=read(),v=read();g[v].push_back(u);U[i]=u,V[i]=v;}
	For(t,1,n)memset(vis,0,sizeof vis),dfs(t),init(f[t],t);
	while(q--){
		int s=read(),t=read(),k=read()-1;
		if(f[t][0][s]>n||f[t][LG-1][f[t][LG-1][s]]<=n)puts("-1");else{
			Rof(i,LG-1,0)if(k>>i&1)s=f[t][i][s];
			cout<<(s>n?-1:s)<<"\n";
		}
	}
	return 0;
}