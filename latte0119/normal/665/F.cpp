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

const int LIM=10000000;
bool isprime[LIM];
int pcnt[LIM];
vint P;
const int K=320000;
const int W=110;
int dp[K][W];

int calc(int n,int k){
    if(n<K){
        if(k>=W){
            if(P[k]>n)return 1;
            return pcnt[n]-k+1;
        }
        return dp[n][k];
    }

    if(k==0)return n;
    if(P[k]>n)return 1;
    return calc(n,k-1)-calc(n/P[k-1],k-1);
}

int calcpi(int n){
    if(n<LIM)return pcnt[n];

    int lb=-1,ub=P.size()-1;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(P[mid]*P[mid]<=n)lb=mid;
        else ub=mid;
    }

    int s=ub;
    int tmp=calc(n,s);
    return tmp+s-1;
}

signed main(){
    fill_n(isprime,LIM,1);
    isprime[0]=isprime[1]=0;
    for(int i=2;i<LIM;i++){
        if(!isprime[i])continue;
        P.pb(i);
        for(int j=i+i;j<LIM;j+=i)isprime[j]=false;
    }

    for(int i=1;i<LIM;i++)pcnt[i]=pcnt[i-1]+isprime[i];
    for(int i=1;i<K;i++){
        dp[i][0]=i;
        for(int j=1;j<W;j++){
            if(P[j]>i){
                dp[i][j]=1;
            }
            else if(P[j]*P[j]>i){
                dp[i][j]=pcnt[i]-j+1;
            }
            else{
                dp[i][j]=dp[i][j-1]-dp[i/P[j-1]][j-1];
            }
        }
    }


    int N;
    cin>>N;
    int ans=0;
    for(auto p:P){
        if(p*p*p>N)break;
        ans++;
    }

    for(int i=0;P[i]*P[i]<=N;i++){
        int tmp=calcpi(N/P[i])-i-1;
        ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}