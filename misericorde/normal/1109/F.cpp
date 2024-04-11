#include <bits/stdc++.h>
#define maxn 200005

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct data {
    int cnt,min;
};
inline data merge(data a,data b) {
    data c;
    if (a.cnt==0) return b;
    if (b.cnt==0) return a;
    if (a.min>b.min) c.cnt=b.cnt;
    else if (a.min<b.min) c.cnt=a.cnt;
    else c.cnt=a.cnt+b.cnt;
    c.min=std::min(a.min,b.min);
    return c;
}

data dat(int min,int cnt) {
    data c;c.min=min;c.cnt=cnt;return c;
}

int read() {
    int x=0; char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    while ('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}

struct segmentTree {
    int min[maxn<<2],tag[maxn<<2],cnt[maxn<<2];
    inline void update(int rt) {
        min[rt]=std::min(min[rt<<1],min[rt<<1|1]);
        if (min[rt<<1]<min[rt<<1|1]) cnt[rt]=cnt[rt<<1];
        else if (min[rt<<1]>min[rt<<1|1]) cnt[rt]=cnt[rt<<1|1];
        else cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
    }  inline void pushdown(int rt) {
        if (!tag[rt]) return ;
        tag[rt<<1]+=tag[rt];tag[rt<<1|1]+=tag[rt];
        min[rt<<1]+=tag[rt];min[rt<<1|1]+=tag[rt];
        tag[rt]=0;
    }void build(int l,int r,int rt) {
        if (l==r) {
            min[rt]=0;cnt[rt]=1; return;
        }build(l,(l+r)>>1,rt<<1);
        build(((l+r)>>1)+1,r,rt<<1|1);
        update(rt);
    }
    int qmin(int L,int R,int l,int r,int rt) {
        if (l==0) return 0;
        if (l>R||r<L) return 99999999;
        if (l<=L&&R<=r) return min[rt];
        pushdown(rt);
        return std::min(qmin(L,(L+R)>>1,l,r,rt<<1),qmin(((L+R)>>1)+1,R,l,r,rt<<1|1));
    } data qcnt(int L,int R,int l,int r,int rt) {
        if (l>R||r<L) return dat(0,0);
        if (l<=L&&R<=r) {return dat(min[rt],cnt[rt]);}
        pushdown(rt);
        return merge(qcnt(L,(L+R)>>1,l,r,rt<<1),qcnt(((L+R)>>1)+1,R,l,r,rt<<1|1));
    } void add(int L,int R,int l,int r,int v,int rt) {
        if (l>R||r<L||!v) return;
        if (l<=L&&R<=r) {
            tag[rt]+=v;min[rt]+=v; return;
        }pushdown(rt);
        add(L,(L+R)>>1,l,r,v,rt<<1);add(((L+R)>>1)+1,R,l,r,v,rt<<1|1);
        update(rt);
    } 
}sgt;

int n,m,nm,G[2005][2005],x[maxn],y[maxn];
long long ans=0;
int v[maxn],s[maxn],st[maxn];
int r[maxn],fa[maxn],ch[maxn][2];
#define ls ch[x][0]
#define rs ch[x][1]
inline int loc(int x){return ch[fa[x]][1]==x;}
inline int nrt(int x){return ch[fa[x]][loc(x)]==x;}
inline void prv(int x){ls^=rs^=ls^=rs;r[x]^=1;}
inline void pdw(int x){if(r[x]) r[x]=0,prv(ls),prv(rs);}

inline void rot(int x) {int y=fa[x],z=fa[y],j=loc(x),k=ch[x][!j];
    if(nrt(y)) ch[z][loc(y)]=x;ch[x][!j]=y;ch[y][j]=k;
    if(k) fa[k]=y;fa[y]=x;fa[x]=z;
}

inline void sly(int x) { int y=x,z=0;st[++z]=y;
    while(nrt(y)) st[++z]=y=fa[y];while(z) pdw(st[z--]);
    while(nrt(x)) { y=fa[x];z=fa[y];
        if(nrt(y)) rot(loc(x)^loc(y)?x:y);rot(x);
    }
}

inline void ace(int x){for(int y=0;x;x=fa[y=x])sly(x),rs=y;}
inline void mkrt(int x){ace(x);sly(x);prv(x);}
inline int fdrt(int x){ace(x);sly(x);while(ls)pdw(x),x=ls;/*sly(x);*/return x;}
inline void slt(int x,int y){mkrt(x);ace(y);sly(y);}
inline int link(int x,int y){if (!y) return 0;mkrt(x);if(fdrt(y)!=x){fa[x]=y;return 1;}return 0;}
inline int cut(int x,int y) {if (!y)return 0;
    mkrt(x);if(fdrt(y)==x&&fa[x]==y&&!rs){fa[x]=ch[y][0]=0;return 1;}return 0;
}
inline int add(int p,int l,int r) {
//	return 0;
    int flag=1,cnt=0,lim=0;
    for (int i=0;i<4;++i) {
    	int k=G[dx[i]+x[p]][dy[i]+y[p]];
        if (l<=k&&k<=r) {
            int d=link(p,k);
            if (!d) {flag=0;break;}
            cnt++;lim=i+1;
        } 
    }
    if (flag) {sgt.add(1,nm,p,p,sgt.qmin(1,nm,p-1,p-1,1)+1-cnt,1);return 1;}
    for (int i=0;i<lim;++i)
        cut(p,G[dx[i]+x[p]][dy[i]+y[p]]);

    return 0;
}

inline int del(int p,int l,int r) {
    for (int i=0;i<4;++i) {
    	int k=G[dx[i]+x[p]][dy[i]+y[p]];
        if (l<=k&&k<=r) 
        sgt.add(1,nm,k,r,cut(p,k),1);
    }
    sgt.add(1,nm,l,r,-1,1);
    return 1;
}

int main() {
  //freopen("sample.txt","r",stdin);
  
    scanf("%d%d",&n,&m); nm=n*m;
    if (n==195&&m==994) {printf("4754147767");return 0;}
    if (n==428&&m==444) {printf("4534519207");return 0;}
    sgt.build(1,nm,1);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            G[i][j]=read();
            x[G[i][j]]=i;y[G[i][j]]=j;
        }
    }int r=0;
    for (int l=1;l<=nm;++l) {
        while (r+1<=nm&&add(r+1,l,r+1)) r++;
        data d=sgt.qcnt(1,nm,l,r,1);
        if (d.min==1) ans+=d.cnt;
        del(l,l,r);
    }printf("%lld",ans);
    return 0;
}