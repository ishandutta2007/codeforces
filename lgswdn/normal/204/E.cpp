#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=4e5+9,inf=0x3f3f3f3f;

int n,k,m,len[N],s[N],bl[N];
char t[N];

namespace SegT {
    int ls[N<<5],rs[N<<5],s[N<<5],tot=1;
    void pushup(int p) {
        if(ls[p]||rs[p]) s[p]=s[ls[p]]+s[rs[p]];
    }
    void ins(int &p,int l,int r,int x) {
        if(!p) p=++tot;
        if(l==r) {s[p]=1; return;} int mid=l+r>>1;
        if(x<=mid) ins(ls[p],l,mid,x); else ins(rs[p],mid+1,r,x);
        pushup(p);
    }
    void merge(int &x,int y) {
        if(!x||!y) {x+=y; return;}
        merge(ls[x],ls[y]), merge(rs[x],rs[y]);
        if(!ls[x]&&!rs[x]) s[x]|=s[y];
        else pushup(x);
    }
    int qry(int p) {return s[p];}
}

namespace SufT {
    int st[N],l[N],link[N],n,now,tot,r,ch[N][29],g[N],gl[N],dep[N],rt[N],fa[N][20],mp[N];
    void init() {l[0]=inf; tot=now=1; r=0;}
    int newn(int s,int ll=inf) {
        ++tot; st[tot]=s, l[tot]=ll, link[tot]=0;
        return tot;
    }
    void add(int x) {
        int last=0; ++r, ++n;
        while(r) {
            while(r>l[ch[now][s[n-r+1]]])
                now=ch[now][s[n-r+1]], r-=l[now];
            int &v=ch[now][s[n-r+1]], c=s[st[v]+r-1];
            if(!v||x==c) {
                link[last]=now, last=now;
                if(!v) v=newn(n-r+1);
                else return;
            } else {
                int u=newn(st[v],r-1);
                ch[u][c]=v, ch[u][x]=newn(n);
                st[v]+=r-1, l[v]-=r-1;
                v=u, link[last]=u, last=u;
            }
            if(now==1) --r; else now=link[now];
        }
    }
    void getlen() {
        rep(i,1,tot) if(l[i]>n) l[i]=n-st[i]+1;
    }
    bool check(int u) {return bl[st[u]]==bl[st[u]+l[u]-1]&&bl[st[u]]>0;}
    void dfs(int u,bool legal) {
        bool lf=1;
        rep(h,1,19) fa[u][h]=fa[fa[u][h-1]][h-1];
        rep(i,1,28) {
            int v=ch[u][i]; if(!v) continue; lf=0;
            dep[v]=dep[u]+l[v], fa[v][0]=u;
            dfs(v,legal&&check(v));
            SegT::merge(rt[u],rt[v]);
        }
        if(lf) {
            SegT::ins(rt[u],1,n,bl[n-dep[u]+1]);
            mp[n-dep[u]+1]=u;
        }
        g[u]=SegT::qry(rt[u])>=k, gl[u]=legal;
    }
    void newlen() {
        rep(i,1,tot) if(!check(i)) {
            int x=1, y=l[i]; l[i]=0; if(bl[st[i]]<0) continue;
            while(x<=y) {
                int mid=x+y>>1;
                if(bl[st[i]]==bl[st[i]+mid-1]) l[i]=mid, x=mid+1;
                else y=mid-1;
            }
        }
    }
    int query(int b,int pos) {
        int u=mp[pos];
        per(h,19,0) if(fa[u][h]&&!(g[fa[u][h]]&&gl[fa[u][h]])) u=fa[u][h];
        return dep[fa[u][0]]+g[u]*l[u];
    }
}

signed main() {
    n=read(), k=read();
    SufT::init(); int cc=0;
    rep(i,1,n) {
        scanf("%s",t+1); len[i]=strlen(t+1);
        rep(j,1,len[i]) SufT::add(s[++cc]=t[j]-'a'+1), bl[cc]=i;
        SufT::add(s[++cc]=27), bl[cc]=-i;
    }
    SufT::add(s[++cc]=28); bl[cc]=-n-1;
    SufT::getlen();
    SufT::dfs(1,1);
    SufT::newlen();
    int ct=0;
    rep(i,1,n) {
        long long ans=0;
        rep(l,1,len[i]) ++ct, ans+=SufT::query(i,ct); ++ct;
        printf("%lld ",ans);
    } puts("");
    return 0;
}