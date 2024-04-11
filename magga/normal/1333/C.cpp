#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int i=0,j=0;
    set<long long int>s;
    long long int dp[n+1];
    long long int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    dp[0]=0;
    s.insert(0);
    long long int ans = 0;
    while(i<n){
        dp[i+1]=dp[i]+arr[i];
        if(s.find(dp[i+1])==s.end()){
            s.insert(dp[i+1]);
            i++;
            continue;
        }
        while(dp[j]!=dp[i+1]){
            ans+=i-j;
            s.erase(dp[j]);
            j++;
        }
        ans+=i-j;
        j++;
        i++;
    }
    while(j<n){
        ans+=n-j;
        j++;
    }
    cout<<ans<<"\n";
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