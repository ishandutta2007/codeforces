#include <bits/stdc++.h>
using namespace std;
const int big=2e7+5;
#define int long long
bool ni[big];
int freq[big],dp[big];
signed main(){
    int n;
    cin>>n;
    vector<int> pp;
    for(int i=2;i<big;i++){
        if(!ni[i]){
            for(int j=i*2;j<big;j+=i)ni[j]=1;
            pp.push_back(i);
        }
    }
    for(int i=0,u;i<n;i++){
        cin>>u;
        freq[u]++;
    }
    for(auto i:pp){
        for(int j=(big-1)/i;j>0;j--)freq[j]+=freq[i*j];
    }
    int ans=-122690412;
    for(int i=big-5;i>0;i--){
        dp[i]+=freq[i]*i;
        for(auto j:pp){
            if(i*j>big-1)break;
            dp[i]=max(dp[i],dp[i*j]+(freq[i]-freq[i*j])*i);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}