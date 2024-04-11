#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e6+10;
char a[N];int s[N],n;
vector<int> g[N];
void add(int u,int v){g[u].push_back(v),g[v].push_back(u);
}
map<int,int> ban[N];
int stk[N],tp,now[N];
void dfs(int u){
	for(int &i=now[u];i<g[u].size();){
		int v=g[u][i++];if(ban[u][v]){ban[u][v]--;continue;}
		ban[v][u]++,dfs(v);
	}stk[++tp]=u;
}
signed main(){
	int T=read();while(T--){
		scanf("%s",a+1),n=strlen(a+1),s[0]=n;
		For(i,0,2*n)g[i].clear(),now[i]=0,ban[i].clear();tp=0;
		For(i,1,n)s[i]=s[i-1]+(a[i]=='0'?-1:1),
			add(s[i-1],s[i]);
		For(i,0,2*n)sort(g[i].begin(),g[i].end());
		dfs(n);
		Rof(i,tp,2)putchar(stk[i]>stk[i-1]?'0':'1');puts("");
	}
	return 0;
}//dadas