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
const int N=4e5+10;
int head[N],to[N],nxt[N],cnt,deg[N];
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int n,rt,fa[N],fl[N];
void dfs(int u,int f){
	fa[u]=f;go(u)if(to[i]!=f)dfs(to[i],u);
}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())head[i]=deg[i]=fl[i]=0;cnt=0,rt=0;
		For(i,2,n){int u=read(),v=read();deg[u]++,deg[v]++,add(u,v),add(v,u);}
		if(n==1)puts("0");else if(n==2)puts("1");else{
			For(i,1,n)if(deg[i]>2){rt=i;break;}
			if(!rt){puts("1");continue;}
			dfs(rt,0);int ans=0;For(i,1,n)if(deg[i]==1){
				ans++;int u=i;do u=fa[u];while(deg[u]<=2);
				if(!fl[u])fl[u]=1,ans--;
			}cout<<ans<<endl;
		}
	}
	return 0;
}