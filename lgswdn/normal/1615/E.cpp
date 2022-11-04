#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9; 

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k,a[N],lf;
vector<int>e[N];

int ls[N],rs[N],val[N],d[N],rt[N],id[N];
int merge(int x,int y) {
    if(x==0||y==0) return x+y;
    if(val[y]>val[x]) swap(x,y);
    rs[x]=merge(rs[x],y);
    if(d[ls[x]]<d[rs[x]]) swap(ls[x],rs[x]);
    d[x]=d[rs[x]]+1;
    return x;
}
int find(int x) {return rt[x]==x?x:rt[x]=find(rt[x]);}
void del(int x) {
    rt[x]=rt[ls[x]]=rt[rs[x]]=merge(ls[x],rs[x]);
    rs[x]=ls[x]=d[x]=0;
}

void dfs(int u,int fa) {
    bool leaf=1;
    for(auto v:e[u]) if(v!=fa) {
        dfs(v,u);
        if(!id[u]) id[u]=id[v];
        else id[u]=merge(id[u],id[v]);
        leaf=0;
    }
    lf+=leaf;
    if(!id[u]) {
        id[u]=u, rt[u]=u, val[u]=a[u];
    } else {
        val[id[u]]+=a[u];
    }
}

signed main() {
    n=read(), k=read();
    rep(i,1,n) a[i]=1;
    rep(i,2,n) {
        int u=read(), v=read();
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs(1,0);
    int ans=0, now=rt[id[1]];
    int ek=k;
    while(now&&k) {
        k--;
        ans+=val[now];
        del(now);
        now=rt[now];
    }
    int rans=-0x3f3f3f3f3f3f3f3f;
    rep(r,min(ek,lf),ek) {
        int x=0;
        if(n/2<=n-ans) x=n/2;
        else x=n-ans;
        rans=max(rans,(n-r-x)*(r-x));
    }
    printf("%lld\n",rans);
    return 0;
}