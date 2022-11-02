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

signed main(){
    int K;
    cin>>K;

    vector<string>W;
    string S;
    while(cin>>S){
        W.pb(S);
    }
    for(int i=0;i+1<W.size();i++)W[i]+="*";


    vint lis;
    for(auto &w:W){
        int cur=0;
        while(cur<w.size()){
            int nex=cur;
            while(nex<w.size()&&w[nex]!='-')nex++;
            if(nex<w.size())nex++;
            lis.pb(nex-cur);
            cur=nex;
        }
    }

    int lb=*max_element(all(lis))-1,ub=1000000;
    while(ub-lb>1){
        int mid=(ub+lb)/2;

        int cnt=1;
        int sum=0;
        for(auto l:lis){
            if(sum+l>mid){
                cnt++;
                sum=0;
            }
            sum+=l;
        }
        if(cnt<=K)ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}