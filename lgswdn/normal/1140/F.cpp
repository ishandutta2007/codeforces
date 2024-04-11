#include<bits/stdc++.h>
#define int long long
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

const int N=6e5+9,lim=3e5;
int q,ans;

namespace DSU {
    int num[N][2],id[N],h[N],s[N][2];
    stack<pair<pii,int> > op; 
    int find(int x) {while(x!=id[x]) x=id[x]; return x;}
    void merge(int x,int y) {
        x=find(x), y=find(y);
        if(x==y) {op.push(make_pair(pii(-1,-1),-1)); return;}
        if(h[x]<h[y]) swap(x,y);
        op.push(make_pair(pii(x,y),h[x]==h[y]));
        id[y]=x; h[x]+=(h[x]==h[y]);
        ans-=s[x][0]*s[x][1]+s[y][0]*s[y][1];
        s[x][0]+=s[y][0], s[x][1]+=s[y][1];
        ans+=s[x][0]*s[x][1];
    }
    void undo() {
        auto p=op.top(); op.pop();
        if(p.se==-1) return;
        int x=p.fi.fi, y=p.fi.se, z=p.se;
        ans-=s[x][0]*s[x][1];
        s[x][0]-=s[y][0], s[x][1]-=s[y][1];
        ans+=s[x][0]*s[x][1]+s[y][0]*s[y][1];
        id[y]=y, h[x]-=z;
    }
    void init() {
        rep(i,1,2*lim) {
            id[i]=i, h[i]=1;
            if(i>lim) s[i][1]=1;
            else s[i][0]=1;
        }
    }
}

namespace SegDC {
    vp e[N<<2];
    void add(int p,int l,int r,int x,int y,pii pp) {
        //if(p==1) cout<<x<<" "<<y<<' '<<pp.fi<<" "<<pp.se<<endl;
        if(l==x&&r==y) {e[p].emplace_back(pp); return;}
        int mid=l+r>>1;
        if(y<=mid) add(p*2,l,mid,x,y,pp);
        else if(x>mid) add(p*2+1,mid+1,r,x,y,pp);
        else add(p*2,l,mid,x,mid,pp), add(p*2+1,mid+1,r,mid+1,y,pp);
    }
    void work(int p,int l,int r) {
        int tot=0; int mid=l+r>>1;
        for(auto x:e[p]) DSU::merge(x.fi,x.se), ++tot;
        if(l!=r) work(p*2,l,mid), work(p*2+1,mid+1,r);
        else if(l!=q+1) printf("%lld ",ans);
        while(tot--) DSU::undo();
    }
}

signed main() {
    q=read();
    DSU::init();
    map<pii,int>mp;
    rep(i,1,q) {
        int x=read(), y=read()+lim; pii pp(x,y);
        if(!mp[pp]) mp[pp]=i;
        else SegDC::add(1,1,q,mp[pp],i-1,pp), mp.erase(mp.find(pp));
    }
    for(auto pp:mp) SegDC::add(1,1,q,pp.se,q,pp.fi);
    SegDC::work(1,1,q); puts("");
    return 0;
}