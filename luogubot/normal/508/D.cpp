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
const int N=2e5+10,M=2e5+10;
vector<int> g[N];
int n,m,fa[N],ind[N],oud[N],head[N],idx;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
map<string,int> mp;string bk[N];inline int id(string s){
	if(!mp[s])mp[s]=++idx,bk[idx]=s;
	if(idx>N-10)puts("NO"),exit(0);
	return mp[s];}

int stk[M],tp;void dfs(int u){for(int &i=head[u];i<g[u].size();)dfs(g[u][i++]);stk[++tp]=u;}
signed main(){
	m=read();
	For(i,1,m){
		string s;cin>>s;int u=id(s.substr(0,2)),v=id(s.substr(1,2));
		g[u].push_back(v),ind[v]++,oud[u]++;
	}For(i,1,idx)fa[i]=i;For(u,1,idx)for(int v:g[u])fa[get(u)]=get(v);
	For(i,1,idx)if(get(i)!=get(1))return puts("NO"),0;else sort(g[i].begin(),g[i].end());
	int st=0,cs=0,ce=0;For(i,1,idx)if(oud[i]){st=i;break;}if(!st)return puts("YES"),0;For(i,1,idx){
		if(oud[i]-ind[i]==1)cs++,st=i;
		else if(ind[i]-oud[i]==1)ce++;
		else if(ind[i]!=oud[i])return puts("NO"),0;
	}if(cs>1||ce>1||(cs^ce))return puts("NO"),0;puts("YES");
	dfs(st);putchar(bk[stk[tp]][0]);while(tp)putchar(bk[stk[tp--]][1]);
	return 0;
}//dsadas