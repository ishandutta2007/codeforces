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
bool ST;
const int N=2e5+10;
int n;
struct node{
	int val,id;
	bool operator < (const node &x) const {
		return val<x.val;
	}
}a[N],b[N];
int head[N],to[N],nxt[N],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
int dfn[N],low[N],idx,in[N],stk[N],tp;
int scnt,num[N],deg[N];vector<int> g[N];
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	in[u]=1,stk[++tp]=u;
	go(u){
		int v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(in[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		scnt++;int x;
		do x=stk[tp--],in[x]=0,num[x]=scnt;
		while(x!=u);
	}
}
map<int,int> mp[N];
bool ED;
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())dfn[i]=low[i]=head[i]=in[i]=num[i]=deg[i]=0,g[i].clear(),mp[i].clear();
		scnt=cnt=tp=0;
		For(i,1,n)a[i]=(node){read(),i};For(i,1,n)b[i]=(node){read(),i};
		sort(a+1,a+1+n),sort(b+1,b+1+n);For(i,2,n)add(a[i].id,a[i-1].id),add(b[i].id,b[i-1].id);
		For(i,1,n)if(!dfn[i])tarjan(i);
		For(u,1,n)go(u)if(num[u]!=num[to[i]]&&!mp[num[u]][num[to[i]]]){
			int x=num[u],y=num[to[i]];
			mp[x][y]=1,deg[y]++;
		}For(i,1,n)putchar(!deg[num[i]]?'1':'0');puts("");
	}
	return 0;
}