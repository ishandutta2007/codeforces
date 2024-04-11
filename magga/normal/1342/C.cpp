#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    int a,b,q;cin>>a>>b>>q;
    int dp[a*b+1];
    dp[0]=0;
    for(int i=1;i<=a*b;i++){
        dp[i]=dp[i-1]+(((i%a)%b)!=((i%b)%a));
    }
    long long int l,r;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        l--;
        long long int ans = (r/(a*b))*dp[a*b]-(l/(a*b))*dp[a*b];
        ans+=dp[r%(a*b)]-dp[l%(a*b)];
        cout<<ans<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}