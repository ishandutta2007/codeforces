#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=int(s[i])-int('a');
    }
    int dp[n];
    int val[26]{0};
    int ans = 0;
    for(int i=0;i<n;i++){
        int woo = 0;
        for(int j=arr[i]+1;j<26;j++){
            woo=max(val[j],woo);
        }
        dp[i]=woo+1;
        val[arr[i]]=dp[i];
        ans=max(dp[i],ans);
    }
    cout<<ans<<"\n";
    for(auto i:dp){
        cout<<i<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}