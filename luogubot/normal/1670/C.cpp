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
const int N=1e5+10,p=1e9+7;
int n,a[N],b[N],c[N],to[N];
int vis[N],fl,sz;void dfs(int u){
	vis[u]=1,fl&=(!c[u]);if(!vis[to[u]])dfs(to[u]);
}
signed main(){
	int T=read();while(T--){
		n=read();For(i,1,n)a[read()]=i,vis[i]=0;For(i,1,n)b[i]=a[read()];For(i,1,n)c[i]=a[read()];int ans=1;
		For(i,1,n)to[i]=b[i];For(i,1,n)if(!vis[i]&&to[i]!=i)fl=1,dfs(i),ans=ans*(1+fl)%p;printf("%lld\n",ans);
	}
	return 0;
}