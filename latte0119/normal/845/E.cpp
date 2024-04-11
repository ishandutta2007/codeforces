#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

int H,W,K;
int XX[555],YY[555];

tuple<vint,vint,vint>calc(int XX[],int W,int t){
    vint xs;
    xs.pb(0);
    xs.pb(W);
    rep(i,K){
        int l=max(0ll,XX[i]-t);
        int r=min(W,XX[i]+1+t);

        xs.pb(l);
        xs.pb(r);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());
    
    vint xl,xr;

    rep(i,K){
        int l=max(0ll,XX[i]-t);
        int r=min(W,XX[i]+1+t);

        l=lower_bound(all(xs),l)-xs.begin();
        r=lower_bound(all(xs),r)-xs.begin();
        xl.pb(l);
        xr.pb(r);
    }

    return make_tuple(xl,xr,xs);
}

int sum[1111][1111];
const int INF=1001001001001001001ll;
bool check(int t){
    vint xl,xr,xs;
    tie(xl,xr,xs)=calc(XX,W,t);
    vint yl,yr,ys;
    tie(yl,yr,ys)=calc(YY,H,t);

    memset(sum,0,sizeof(sum));
    rep(i,K){
        sum[yl[i]][xl[i]]++;
        sum[yr[i]][xl[i]]--;
        sum[yl[i]][xr[i]]--;
        sum[yr[i]][xr[i]]++;
    }

    rep(i,ys.size()){
        rep(j,xs.size()){
            sum[i][j+1]+=sum[i][j];
        }
    }

    rep(i,ys.size()){
        rep(j,xs.size()){
            sum[i+1][j]+=sum[i][j];
        }
    }

    int miny=INF,maxy=0,minx=INF,maxx=0;
    for(int i=0;i+1<ys.size();i++){
        for(int j=0;j+1<xs.size();j++){
            if(sum[i][j])continue;
            chmin(miny,ys[i]);
            chmax(maxy,ys[i+1]);

            chmin(minx,xs[j]);
            chmax(maxx,xs[j+1]);
        }
    }

    int req=max((maxy-miny-1+1)/2,(maxx-minx)/2);
    return req<=t;
}

signed main(){
     cin>>W>>H>>K;
     rep(i,K)cin>>XX[i]>>YY[i],XX[i]--,YY[i]--;

     int lb=-1,ub=1000000000;
     while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(check(mid))ub=mid;
        else lb=mid;
     }
     cout<<ub<<endl;
    return 0;
}