#include<bits/stdc++.h>
using namespace std;
int val(char c){
    return int(c)-int('a');
}
void pre(){}
void solve(){
    string s;cin>>s;
    long long int n = s.size();
    long long int arr[26]{0};
    long long int dp[26][26]{0};
    for(char c:s){
        arr[val(c)]++;
    }
    long long int ans = 0;
    for(long long int i=0;i<26;i++){
        ans=max(ans,arr[i]);
    }
    for(long long int i=0;i<n;i++){
        arr[val(s[i])]--;
        for(long long int j=0;j<26;j++){
            dp[val(s[i])][j]+=arr[j];
        }
    }
    for(long long int i=0;i<26;i++){
        for(long long int j=0;j<26;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}