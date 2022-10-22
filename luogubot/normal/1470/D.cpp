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
int n,m;
vector<int> g[N];
int dfn[N],idx,c[N],p[N];
void dfs(int u){
	dfn[u]=++idx,p[idx]=u;
	for(int v:g[u])if(!dfn[v])dfs(v);
}
signed main(){
	int T=read();while(T--){
		n=read(),m=read(),idx=0;
		For(i,1,n)g[i].clear(),c[i]=0,dfn[i]=0;
		For(i,1,m){
			int u=read(),v=read();
			g[u].push_back(v),g[v].push_back(u);
		}dfs(1);if(idx!=n){puts("NO");continue;}
		int tot=0;For(i,1,n){
			int u=p[i],fl=0;
			for(int v:g[u])if(dfn[v]<dfn[u]){
				fl|=c[v];
			}if(!fl)c[u]=1,tot++;
		}puts("YES"),printf("%d\n",tot);
		For(i,1,n)if(c[i])printf("%d ",i);puts("");
	}
	return 0;
}