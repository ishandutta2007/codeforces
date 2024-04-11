#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
#define endout fflush(stdout)
using namespace std;
inline int read(){
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
   return x*f;
}
const int N=2e6+10;
int head[N],to[N],nxt[N],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
int vis[N],cur[N],n;
vector<int> g[N];
void dfs(int u){
	vis[u]=1;go(u){
		int v=to[i];if(!vis[v])
			cur[v]=cur[u]^1,dfs(v); 
	}
}
void print(int c){
	For(i,1,n){
		if(cur[g[i][0]]==c)printf("%lld ",g[i][0]);
		else printf("%lld ",g[i][1]);
	}endout;
}
signed main(){
	n=read();
	if(n%2==0){
		puts("First");endout;
		For(j,0,1)For(i,1,n)printf("%lld ",i);puts("");endout;
	}
	else{
		puts("Second");endout;
		For(i,1,n)add(i,i+n),add(i+n,i);
		For(i,1,2*n)g[read()].push_back(i);
		For(i,1,n)add(g[i][0],g[i][1]),add(g[i][1],g[i][0]);
		For(i,1,2*n)if(!vis[i])dfs(i);
		int res=0;For(i,1,2*n)if(cur[i])res+=i;
		(res%(2*n)==0)?print(1):print(0);
	}return 0;
}