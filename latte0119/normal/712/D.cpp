#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
int dp[2][666666];
inline void add(int &a,int b){
    a+=b;
    if(a>=b)a-=mod;
    if(a<0)a+=mod;
}


signed main(){
    int A,B,K,T;
    cin>>A>>B>>K>>T;
    dp[0][A-B+300000]=1;

    for(int i=0;i<2*T;i++){
        int sum=0;
        for(int j=0;j<2*K+1;j++)add(sum,dp[i&1][j]);
        for(int j=K;j+K+1<666666;j++){
            dp[(i+1)&1][j]=sum;
            add(sum,dp[i&1][j-K]);
            add(sum,-dp[i&1][j+K+1]);
        }
    }

    int ans=0;
    for(int i=300000+1;i<666666;i++)add(ans,dp[0][i]);
    cout<<ans<<endl;
    return 0;
}