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

int n,s[N],ans;
char t[N];

namespace SegT {
    int ls[N<<5],rs[N<<5],tot=1;
    int newn(int x=0) {
        ++tot; ls[tot]=ls[x], rs[tot]=rs[x];
        return tot;
    }
    void insert(int &p,int l,int r,int x) {
        p=newn();
        if(l==r) return; int mid=l+r>>1;
        if(x<=mid) insert(ls[p],l,mid,x);
        else insert(rs[p],mid+1,r,x);
    }
    void merge(int &x,int y) {
        if((!x)||(!y)) {x+=y; return;}
        x=newn(x);
        merge(ls[x],ls[y]), merge(rs[x],rs[y]);
    }
    int qry(int p,int l,int r,int x,int y) {
        if(l>r) return 0;
        if(!p) return 0;
        if(l==x&&r==y) return 1; int mid=l+r>>1;
        if(y<=mid) return qry(ls[p],l,mid,x,y);
        else if(x>mid) return qry(rs[p],mid+1,r,x,y);
        else return qry(ls[p],l,mid,x,mid)|qry(rs[p],mid+1,r,mid+1,y);
    }
}

namespace SufT {
    int tot,n,ch[N<<1][29],st[N<<1],l[N<<1],link[N<<1],dep[N<<1],rt[N<<1],pos[N<<1],f[N<<1],tp[N<<1],now,r;
    void init() {
        now=1, n=r=0, tot=1, l[0]=inf;
    }
    int newn(int stt,int len=inf) {
        ++tot; st[tot]=stt, l[tot]=len, link[tot]=1;
        return tot;
    }
    void extend(int x) {
        r++, n++; int last=1;
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
            if(now==1) r--; else now=link[now];
        }
    }
    void getlen() {
        rep(i,1,tot) if(l[i]>n) l[i]=n-st[i]+1;
    }
    void dfs(int u) {
        int lf=1; pos[u]=n+1;
        rep(i,0,26) {
            int v=ch[u][i]; if(!v) continue; lf=0;
            dep[v]=dep[u]+l[v];
            dfs(v); SegT::merge(rt[u],rt[v]); pos[u]=min(pos[u],pos[v]);
        }
        if(lf) {
            pos[u]=n-dep[u]+1;
            SegT::insert(rt[u],1,n,n-dep[u]+1);
        }
    }
    void dfs2(int u) {
        ans=max(ans,f[u]);
        rep(i,0,26) {
            int v=ch[u][i]; if(!v) continue;
            f[v]=f[u];
            if(u==1) tp[v]=v, f[v]=1;
            else if(SegT::qry(rt[tp[u]],1,n,pos[v]+1,pos[v]+dep[v]-dep[tp[u]])) f[v]++, tp[v]=v;
            else tp[v]=tp[u];
            dfs2(v);
        }
    }
}

signed main() {
    scanf("%d%s",&n,t+1); t[++n]='a'+26;
    SufT::init();
    rep(i,1,n) s[i]=t[i]-'a', SufT::extend(s[i]);
    SufT::getlen();
    SufT::dfs(1);
    SufT::dfs2(1);
    printf("%d\n",max(ans,1));
    return 0;
}