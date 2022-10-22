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
int n,a,b,da,db;
int d[2][N];
vector<int> g[N];
void dfs(int u,int f,int* d){
	for(int v:g[u])if(v!=f)d[v]=d[u]+1,dfs(v,u,d);
}
int res,dep[N],ans;
void dfs2(int u,int f){
	if(dep[u]>ans)ans=dep[u],res=u;
	for(int v:g[u])if(v!=f)dep[v]=dep[u]+1,dfs2(v,u);
}
signed main(){
	int T=read();while(T--){
		n=read(),a=read(),b=read(),da=read(),db=read();
		For(i,1,n)g[i].clear(),d[0][i]=d[1][i]=0;
		For(i,2,n){
			int u=read(),v=read();
			g[u].push_back(v),g[v].push_back(u);	
		}
		int mxlen=0;
		For(i,1,n)dep[i]=0;res=0,ans=-1,dfs2(1,0);int rt=res;
		For(i,1,n)dep[i]=0;res=0,ans=-1;dfs2(rt,0);mxlen=ans;
		dfs(a,0,d[0]),dfs(b,0,d[1]);int fl=0;
		if(db<=2*da||d[0][b]<=da||mxlen<=2*da){puts("Alice");continue;}
		puts("Bob");
	}
	return 0;
}