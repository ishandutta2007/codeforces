#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
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

const int INF=1001001001;

void solve(){
    int N;scanf("%lld",&N);
    map<int,int>cnt;
    rep(i,N){
        int a;scanf("%lld",&a);
        cnt[a]++;
    }

    int ans=N;
    int lim=INF;
    for(auto &p:cnt)chmin(lim,p.se+1);

    for(int s=2;s<=lim;s++){
        int m=0;
        for(auto &p:cnt){
            int d=p.se/(s-1);
            int r=p.se%(s-1);
            if(d<r){
                m+=INF;
                continue;
            }
            m+=r;
            d-=r;
            int tmp=d/s;
            d-=s*tmp;
            m+=(s-1)*tmp;
            m+=d;
        }
        chmin(ans,m);
    }
    cout<<ans<<endl;
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--)solve();
    return 0;
}