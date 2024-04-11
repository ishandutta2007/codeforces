#include<bits/stdc++.h>
#define ll long long
#define inf 2139062143
#define MAXN 200100
#define MOD 998244353
#define rep(i,s,t) for(register int i=(s),i##__end=(t);i<=i##__end;++i)
#define dwn(i,s,t) for(register int i=(s),i##__end=(t);i>=i##__end;--i)
#define ren for(register int i=fst[x];i;i=nxt[i])
#define pb(i,x) vec[i].push_back(x)
#define pls(a,b) (a+b)%MOD
#define mns(a,b) (a-b+MOD)%MOD
#define mul(a,b) (1LL*(a)*(b))%MOD
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,fst[MAXN],nxt[MAXN<<1],to[MAXN<<1],cnt,ind[MAXN];
int rt[MAXN],ls[MAXN],rs[MAXN],dis[MAXN];
ll ans,v[MAXN];
void add(int u,int v) {nxt[++cnt]=fst[u],fst[u]=cnt,to[cnt]=v,ind[v]++;}
int merge(int x,int y)
{
    if(!(x*y)) return x|y;if(v[x]<v[y]) swap(x,y);
    rs[x]=merge(rs[x],y);if(dis[ls[x]]<dis[rs[x]]) swap(ls[x],rs[x]);
    dis[x]=dis[rs[x]]+1;return x;
}
int o;
void dfs(int x,int pa)
{
	int flg=1;
    if(ind[x]==1) rt[x]=x;ren if(to[i]^pa)
        {dfs(to[i],x);flg=0;rt[x]=merge(rt[x],rt[to[i]]);}
    v[rt[x]]++;o+=flg;
}
int main()
{
    n=read(),m=read();int a,b;
    rep(i,2,n) a=read(),b=read(),add(a,b),add(b,a);
    dfs(1,0);
    rep(i,1,m) {ans+=v[rt[1]];rt[1]=merge(ls[rt[1]],rs[rt[1]]);}
    int tp=n-ans;ll res=1ll*(m-tp)*(n-m-tp);
    rep(i,0,tp) res=min(res,1ll*(m-i)*(n-m-i));
    if (o<m)
    {
    	rep(i,o,m) res=max(res,1ll*i*(n-i));
	}
	cout<<res;
}