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

int N;


signed main(){
    scanf("%lld",&N);
    vpint lis;
    rep(i,N){
        int l,r;
        scanf("%lld%lld",&l,&r);
        r++;
        lis.eb(l,r);
    }

    map<int,vpint>evs;
    rep(i,N){
        evs[lis[i].fi].eb(1,i);
        evs[lis[i].se].eb(-1,i);
    }

    set<int>rd;

    set<int>s;
    for(auto &ev:evs){
        vpint &v=ev.se;

        for(auto &p:v){
            if(p.fi==-1){
                s.erase(p.se);
            }
            if(p.fi==1){
                s.insert(p.se);
            }
        }
        if(s.size()==1){
            rd.insert(*s.begin());
        }
    }

    rep(i,N){
        if(rd.find(i)!=rd.end())continue;
        cout<<i+1<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}