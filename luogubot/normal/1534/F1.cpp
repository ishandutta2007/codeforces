#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=4e5+10;
int a[N];
set<int> s[N];
int n,m;
int head[N],to[N*10],nxt[N*10],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline int id(int i,int j){
	return (i-1)*m+j;
}
char ch[N];
int dfn[N],low[N],idx,in[N],stk[N],tp;
int scnt,num[N];vector<int> g[N];int deg[N];
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
//printf("(%d,%d) -> (%d,%d)\n",);
map<int,int> mp[N];
signed main(){
	n=read(),m=read();For(i,1,n){
		scanf("%s",ch+1);For(j,1,m)if(ch[j]=='#')
			a[id(i,j)]=1,s[j].insert(i);
	}For(j,1,m)s[j].insert(n+1);
	For(i,1,n)For(j,1,m)if(a[id(i,j)]==1){
		if(i>1){
			if(a[id(i-1,j)])add(id(i,j),id(i-1,j));
		}auto it=s[j].upper_bound(i);
		int k=*it;
		if(k<=n)add(id(i,j),id(k,j));
		if(j>1){ 
			it=s[j-1].lower_bound(i);
			if(*it<=k&&*it<=n)add(id(i,j),id(*it,j-1));
		}if(j<m){
			it=s[j+1].lower_bound(i);
			if(*it<=k&&*it<=n)add(id(i,j),id(*it,j+1));
		}
	}
	For(i,1,n*m)if(!dfn[i]&&a[i])tarjan(i);
	For(u,1,n*m)go(u)if(num[u]!=num[to[i]]&&!mp[num[u]][num[to[i]]]){
		int x=num[u],y=num[to[i]];
		g[x].push_back(y);
		mp[x][y]=1,deg[y]++;
	}int ans=0;
	For(i,1,scnt)if(!deg[i])ans++;cout<<ans<<endl;
	return 0;
}