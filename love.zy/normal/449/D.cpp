#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007
#define eps 1e-8
#define inf 1e18
const double PI = acos(-1);

using namespace std;

int x[1000001];
int dp[1000001][20];
int dp1[1000001][20];
int f(int x1,int k){
    if(x1 > 1e6)
        return 0;
    if(k >=  20)
        return x[x1];
    int r =0;
    if(dp[x1][k]!= -1)
        return dp[x1][k];
    if(dp1[x1][k] != -1){
        r = f(x1|(1<<dp1[x1][k]),k);
    }
    r += f(x1,k+1);
    return dp[x1][k] = r;
}
ll pw[1000001];
int main(){
    memset(dp,-1,sizeof dp);
    memset(dp1,-1,sizeof dp1);
    for(int i=0 ; i<=1e6 ;i ++){
        int k =0 ;
        for(int j=0 ;j <20 ; j++){
            if(!(i&(1<<j))){
                dp1[i][k++] = j;
            }
        }
    }
    int n,y;
    cin>>n;
    for(int i=0 ;i <n ;i ++){
        scanf("%d",&y);
        x[y]++;
    }
    for(int i=0 ; i<=1e6 ; i++)
        f(i,0);
    pw[0] = 1;
    for(int i=1 ;i<=1e6 ; i++){
        pw[i] = pw[i-1]*2;
        pw[i] %= mod;
    }
    ll res = pw[n]-1;
    if(res < 0)
        res = mod-1;
    for(int i=1 ;i <= 1e6 ; i++){
        bool k =0;
        for(int j=0 ;j <20 ; j++){
            if(i&(1<<j)){
                k = !k;
            }
        }
        if(dp[i][0] <= 0)
            continue;
        //cout<<i<<" "<<dp[i][0]<<endl;
        if(k){
            res -= (pw[dp[i][0]]-1)%mod;
            res %= mod;
            res += mod;
            res %=mod;
        }
        else{
            res += (pw[dp[i][0]]-1)%mod;
            res %= mod;
            res += mod;
            res %=mod;
        }
    }
    cout<<res<<endl;
    return 0;
}