#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef vector<int> vec;
typedef pair<int,int> pii;
const int N=1e6+9,mod=1e9+7;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct seg {int l,r,mx,tag;} t[N<<2];
void build(int p,int l,int r) {
    t[p].l=l, t[p].r=r, t[p].mx=t[p].tag=0;
    if(l==r) return; int mid=(l+r)/2;
    build(p*2,l,mid), build(p*2+1,mid+1,r);
}
void pushdown(int p) {
    t[p*2].tag=max(t[p*2].tag,t[p].tag), t[p*2+1].tag=max(t[p*2+1].tag,t[p].tag);
    t[p*2].mx=max(t[p*2].mx,t[p].tag), t[p*2+1].mx=max(t[p*2+1].mx,t[p].tag);
    t[p].tag=0;
}
void mdf(int p,int x,int y,int v) {
    int l=t[p].l, r=t[p].r, mid=(l+r)/2;
    if(l==x&&r==y) {t[p].mx=max(t[p].mx,v), t[p].tag=max(t[p].tag,v); return;}
    if(t[p].tag) pushdown(p);
    if(y<=mid||x>mid) mdf(p*2+(x>mid),x,y,v);
    else mdf(p*2,x,mid,v), mdf(p*2+1,mid+1,y,v);
    t[p].mx=max(t[p*2].mx,t[p*2+1].mx);
}
int qry(int p,int x,int y) {
    int l=t[p].l, r=t[p].r, mid=(l+r)/2;
    if(l==x&&r==y) return t[p].mx;
    if(t[p].tag) pushdown(p);
    if(y<=mid||x>mid) return qry(p*2+(x>mid),x,y);
    else return max(qry(p*2,x,mid),qry(p*2+1,mid+1,y));
}

int n,m,f[N];
vector<int>p;
vector<pii>a[N];
map<int,int>mp;
vector<int>g[N];

void discrete() {
    sort(p.begin(),p.end());
    int cnt=0;
    rep(i,1,2*m) {
        if(p[i]!=p[i-1]) cnt++, mp[p[i]]=cnt;
    }
}

int main() {
    n=read(), m=read(); p.push_back(0);
    rep(i,1,m) {
        int x=read(), l=read(), r=read();
        p.push_back(l), p.push_back(r);
        a[x].push_back(pii(l,r));
    }
    discrete();
    rep(i,1,n) {
        for(int j=0;j<a[i].size();j++) {
            int l=a[i][j].first, r=a[i][j].second;
            l=mp[l], r=mp[r];
            a[i][j]=pii(l,r);
        }
    }
    build(1,1,2*m);
    rep(i,1,n) {
        for(auto pp:a[i]) {
            int l=pp.first, r=pp.second;
            f[i]=max(f[i],qry(1,l,r)+1);
        }
        for(auto pp:a[i]) {
            int l=pp.first, r=pp.second;
            mdf(1,l,r,f[i]);
        }
    }
    int ans=0x3f3f3f3f;
    rep(i,1,n) ans=min(ans,n-f[i]);
    printf("%d\n",ans);
    rep(i,1,n-ans) g[f[i]].push_back(i);
    int lst=n+1;
    build(1,1,2*m);
    int nw=0;
    rep(i,1,n) if(n-f[i]==ans) {nw=i; break;}
    per(i,n,nw+1) printf("%d ",i);
    for(auto pp:a[nw]) {
        int l=pp.first, r=pp.second;
        mdf(1,l,r,1);
    }
    int tmp=1; lst=nw;
    vector<int>del;
    per(i,nw-1,1) {
        int mx=0;
        for(auto pp:a[i]) {
            int l=pp.first, r=pp.second;
            mx=max(mx,qry(1,l,r));
        }
        if(mx==tmp&&f[i]==n-ans-tmp) {
            tmp++;
            for(auto pp:a[i]) {
                int l=pp.first, r=pp.second;
                mdf(1,l,r,tmp);
            }
            lst=i;
        } else del.push_back(i);
    }
    for(auto x:del) printf("%d ",x);
    return 0;
}