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

int N,M;
int D[333333];
signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        int a,b,d;
        scanf("%lld%lld%lld",&a,&b,&d);
        a--;b--;
        D[a]-=d;
        D[b]+=d;
    }

    vint src,snk;
    rep(i,N){
        if(D[i]>0)src.pb(i);
        else if(D[i]<0)snk.pb(i);
    }


    vector<tuple<int,int,int>>ans;
    while(snk.size()){
        int b=src.back();
        src.pop_back();
        int a=snk.back();
        snk.pop_back();

        int tmp=min(D[b],-D[a]);
        ans.eb(a,b,tmp);
        D[a]+=tmp;
        D[b]-=tmp;
        if(D[b])src.pb(b);
        if(D[a]<0)snk.pb(a);
    }
    printf("%lld\n",(int)ans.size());
    for(auto &tap:ans){
        int a,b,d;
        tie(a,b,d)=tap;
        printf("%lld %lld %lld\n",a+1,b+1,d);
    }
    return 0;
}