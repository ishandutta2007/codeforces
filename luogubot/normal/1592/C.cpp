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
int n,k,a[N];vector<int> g[N];
void pre(int u,int f){for(int v:g[u])if(v!=f)pre(v,u),a[u]^=a[v];}
int fl;
int dfs(int u,int f,int o){
	o|=(!a[u]);int r=0,k=0;
	for(int v:g[u])if(v!=f){
		if(o&&a[v]==a[1])fl=1;
		k+=dfs(v,u,o)||(a[v]==a[1]);
	}if(k>=2)fl=1;return k;
}
signed main(){
	int T=read();while(T--){
		n=read(),k=read();For(i,1,n)a[i]=read(),g[i].clear();
		For(i,2,n){int u=read(),v=read();g[u].push_back(v),g[v].push_back(u);}
		pre(1,0);if(!a[1]){
			puts("YES");continue;
		}if(k>2){
			fl=0,dfs(1,0,0);
			if(fl){puts("YES");continue;}
		}puts("NO");
	}
	return 0;
}