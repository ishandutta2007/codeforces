#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll dp[5050][5050];
ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int sz=n/k+((n%k)>0);
    int ss=0;
    if (n%k>0){
        ss=k-(n%k);
    }
    for (int i=0;i<5050;i++){
        for (int ii=0;ii<5050;ii++){
            dp[i][ii]=inf;
        }
    }
    //cout<<k-ss<<" "<<ss<<" "<<sz<<endl;
    dp[0][0]=0;
    for (int i=0;i<=k-ss;i++){
        for (int ii=0;ii<=ss;ii++){
            if (i<k-ss||ii<ss){
                int ac=(i+ii)*sz-ii;
                //cout<<i<<" "<<ii<<" "<<dp[i][ii]<<" "<<ac<<endl;
                if (i<k-ss){
                    dp[i+1][ii]=min(dp[i+1][ii], dp[i][ii]+(a[ac+sz-1]-a[ac]));
                }
                if (ii<ss){
                    dp[i][ii+1]=min(dp[i][ii+1], dp[i][ii]+(a[ac+sz-2]-a[ac]));
                }
            }
        }
    }
    cout<<dp[k-ss][ss]<<endl;
}