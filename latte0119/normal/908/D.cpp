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

const int mod=1000000007;

int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

int memo[1111][1111];
int K,PA,PB;
int invPA,invPB;
int solve(int n,int a){
    if(n>=K)return 0;
    int &ret=memo[n][a];
    if(ret!=-1)return ret;
    if(a==K){
        ret=(K+invPB-1+mod)%mod;
    }
    else if(a==0){
        ret=solve(n,1);
    }
    else{
        ret=(PA*solve(n,a+1)+PB*(solve(n+a,a)+a))%mod;
    }

    return ret;
}

signed main(){
    cin>>K>>PA>>PB;
    int latte=PA+PB;
    latte=mpow(latte,mod-2);
    PA=PA*latte%mod;
    PB=PB*latte%mod;

    invPA=mpow(PA,mod-2);
    invPB=mpow(PB,mod-2);

    memset(memo,-1,sizeof(memo));
    cout<<solve(0,0)<<endl;
    return 0;
}