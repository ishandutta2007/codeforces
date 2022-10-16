#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,a,b,d1,d2;cin>>n>>a>>b;
    vector<pair<pair<long long int,long long int>,long long int>> arr;
    for(long long int i=0;i<n;i++){
        cin>>d1>>d2;
        if(a<d1 && b<d2){
            arr.push_back({{d1,d2},i});
        }
    }    
    sort(arr.begin(),arr.end());
    n=arr.size();
    long long int flag[n];
    long long int dp[n];
    dp[0]=1;
    long long int ans = 0;
    long long int floo = 0;
    for(long long int i=0;i<n;i++){
        dp[i]=1;
        for(long long int j=0;j<i;j++){
            if(arr[i].first.first>arr[j].first.first && arr[i].first.second>arr[j].first.second){
                if(dp[i]<dp[j]+1){
                    dp[i]=max(dp[j]+1,dp[i]);
                    flag[i]=j;
                }
            }
        }
        if(ans<dp[i]){
            floo=i;
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    long long int grr[ans];
    for(long long int i=0;i<ans;i++){
        grr[ans-1-i]=arr[floo].second+1;
        floo = flag[floo];
    }
    for(auto i:grr){
        cout<<i<<" ";  
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}