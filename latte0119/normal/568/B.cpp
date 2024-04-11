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

int C[4010][4010];

int N;

inline void add(int &a,int b){
    if((a+=b)>=mod)a-=mod;
}
int dp[4444];

signed main(){
    cin>>N;

    for(int i=0;i<=N;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }

    dp[0]=1;
    for(int i=2;i<=N;i++){
        for(int j=2;j<=i;j++){
            add(dp[i],dp[i-j]*C[i-1][j-1]%mod);
        }
    }

    int ans=0;
    int p=1;
    for(int i=1;i<=N;i++){
        p=p*2%mod;
        ans=(ans+dp[N-i]*C[N][i]%mod*(p-1+mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}