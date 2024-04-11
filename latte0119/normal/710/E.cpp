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

const int INF=1001001001001001001;

int table[1<<24];
signed main(){
    int n,x,y;
    cin>>n>>x>>y;

    for(int i=0;i<1<<24;i++){
        int w=i;
        while(w){
            if((w&1)==0){
                w>>=1;
                continue;
            }

            if(!(w>>1&1)){
                table[i]++;
                w>>=2;
                continue;
            }

            table[i]++;
            while(true){
                while(w&1)w>>=1;
                table[i]++;
                if(!(w>>1&1))break;
                w>>=1;
            }
        }
    }

    int ans=INF;
    for(int k=0;k<25;k++){
        int tmp=0;
        tmp+=(n>>k)*x;
        tmp+=table[n&((1<<k)-1)]*x;
        tmp+=k*y;
        chmin(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}