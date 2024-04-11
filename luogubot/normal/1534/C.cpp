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
const int N=4e5+10,mod=1e9+7;
int n,a[N],p[N],vis[N];
void dfs(int u){vis[u]=1;if(!vis[p[u]])dfs(p[u]);}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[read()]=i;
		For(i,1,n)p[i]=a[read()],vis[i]=0;int ans=1;
		For(i,1,n)if(!vis[i])dfs(i),(ans<<=1)%=mod;
		cout<<ans<<endl;
	}
	return 0;
}