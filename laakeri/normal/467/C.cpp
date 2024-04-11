#include <iostream>

using namespace std;

typedef long long ll;

ll dp[5010][5010];

ll st[5001];

ll sum(ll a, ll b){
    if (a==0) return st[b];
    return st[b]-st[a-1];
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        cin>>st[i];
        if (i) st[i]+=st[i-1];
    }
    ll v=0;
    for (int i=0;i<=n;i++){
        for (int ii=0;ii<=k;ii++){
            //cout<<i<<" "<<ii<<" "<<dp[i][ii]<<endl;
            if (ii==k) v=max(v, dp[i][ii]);
            if (ii<k&&i+m<=n){
                dp[i+m][ii+1]=max(dp[i+m][ii+1], dp[i][ii]+sum(i, i+m-1));
            }
            dp[i+1][ii]=max(dp[i+1][ii], dp[i][ii]);
        }
    }
    cout<<v<<endl;
}