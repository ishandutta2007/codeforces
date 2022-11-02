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
    int N;cin>>N;
    
    int cur=0;
    stack<int>s;
    int o=0;
    int cnt=0;
    rep(i,N){
        int t;scanf("%lld",&t);
        int v;
       if(t==1||t==3){
            scanf("%lld",&v);
        }

        if(t==1){
            cur=v;
        }

        if(t==2){
             cnt+=o;
             o=0;
        }
        if(t==3){
            s.push(v);
        }
        if(t==4){
            o=0;
        }
        if(t==5){
            s=stack<int>();
        }
        if(t==6){
            o++;
        }
        while(s.size()&&s.top()<cur){
            s.pop();
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}