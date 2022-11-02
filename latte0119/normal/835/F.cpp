#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001ll;

int ans;

int N;
vpint G[222222];
bool lo[222222];
int h[222222];

const int SEG=1<<19;
struct data{
    int ma,l,r;
    data(int a,int b,int c):ma(a),l(b),r(c){}
    data(){}
}e(-INF,-INF,-INF);

data operator+(const data &a,const data &b){
    data c;
    c.ma=max({a.ma,b.ma,a.l+b.r});
    c.l=max(a.l,b.l);
    c.r=max(a.r,b.r);
    return c;
}
data dat[SEG*2];
data query(int a,int b,int k=0,int l=0,int r=SEG){
    if(r<=a||b<=l)return e;
    if(a<=l&&r<=b)return dat[k];
    return query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2,r);
}

void init(int k,int l,int r,vint &sum,vint &val){
    if(l+1==r){
        if(l>=sum.size()){
            dat[k]=e;
            return;
        }
        dat[k].ma=-INF;
        dat[k].l=val[l]-sum[l];
        dat[k].r=val[l]+sum[l];
        return;
    }

    init(k*2+1,l,(l+r)/2,sum,val);
    init(k*2+2,(l+r)/2,r,sum,val);
    dat[k]=dat[k*2+1]+dat[k*2+2];

}

void dfs(int v,int p){
    vint d={0,0};
    for(auto e:G[v]){
        if(lo[e.fi]||e.fi==p)continue;
        dfs(e.fi,v);
        d.pb(h[e.fi]+e.se);
    }
    sort(all(d));
    reverse(all(d));
    chmax(ans,d[0]+d[1]);
    h[v]=d[0];
}

signed main(){
    cin>>N;
    vint deg(N);
    map<pint,int>cost;
    rep(i,N){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        G[a].pb({b,c});G[b].pb({a,c});
        deg[a]++;deg[b]++;
        cost[{a,b}]=cost[{b,a}]=c;
    }
    queue<int>que;
    rep(i,N)if(deg[i]==1)que.push(i);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto e:G[v]){
            if(deg[e.fi]==1)continue;
            if(--deg[e.fi]==1)que.push(e.fi);
        }
    }

    vint vs;
    rep(i,N)if(deg[i]==2){
        vs.pb(i);
        lo[i]=true;
        break;
    }

    for(int i=0;i<vs.size();i++){
        for(auto e:G[vs[i]]){
            if(deg[e.fi]==1||lo[e.fi])continue;
            lo[e.fi]=true;
            vs.pb(e.fi);
            break;
        }
    }


    rep(i,vs.size())dfs(vs[i],-1);

    int n=vs.size();
    vint sum(2*n);
    vint val(2*n);

    for(int i=1;i<2*n;i++)sum[i]=sum[i-1]+cost[{vs[i%n],vs[(i-1+n)%n]}];
    for(int i=0;i<2*n;i++)val[i]=h[vs[i%n]];
    init(0,0,SEG,sum,val);
    int mi=INF;



    rep(i,n){
        data x=query(i,i+n);
        chmin(mi,query(i,i+n).ma);
    }

    cout<<max(ans,mi)<<endl;
    return 0;
}