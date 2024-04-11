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
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int dp[2][5555];

int N;
int A[5555];

signed main(){
    cin>>N;
    rep(i,N){
        char c;cin>>c;
        A[i]=c=='f';
    }

    dp[0][0]=1;
    for(int i=0;i<N;i++){
        int sum=0;
        for(int j=N;j>=0;j--){
            add(sum,dp[i&1][j]);
            if(i&&A[i-1]){
                if(A[i])add(dp[(i+1)&1][j+1],dp[i&1][j]);
                else add(dp[(i+1)&1][j],dp[i&1][j]);
            }
            else{
                if(A[i])add(dp[(i+1)&1][j+1],sum);
                else add(dp[(i+1)&1][j],sum);
            }
            dp[i&1][j]=0;
        }
    }

    cout<<accumulate(dp[N&1],dp[N&1]+N+1,0ll)%mod<<endl;
    return 0;
}