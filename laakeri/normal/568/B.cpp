#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll ncr[4040][4040];

ll pot(ll x, ll p){
    if (p==0) return 1;
    if (p%2==0){
        ll r=pot(x, p/2);
        return (r*r)%mod;
    }
    return (x*pot(x, p-1))%mod;
}

int is[4040];
ll dp[4040];

ll get(int n){
    if (n==0) return 1;
    if (n==1) return 0;
    if (n==2) return 1;
    if (is[n]) return dp[n];
    ll r=0;
    for (int i=1;i<n;i++){
        r+=ncr[n-1][i]*get(n-i-1);
        r%=mod;
    }
    is[n]=1;
    dp[n]=r;
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if (n==1){
        cout<<1<<endl;
        return 0;
    }
    ncr[0][0]=1;
    for (int i=1;i<=n;i++){
        ncr[i][0]=1;
        for (int j=1;j<=n;j++){
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }
    ll v=0;
    for (int i=0;i<n;i++){
        //cout<<i<<" "<<get(i)<<endl;
        v+=((get(i)*ncr[n][i])%mod)*((pot(2, n-i)-1ll+mod)%mod);
        v%=mod;
    }
    cout<<v<<endl;
}