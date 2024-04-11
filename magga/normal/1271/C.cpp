#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    long long int s[2];cin>>s[0]>>s[1];
    long long int x,y;
    pair<long long int,long long int> dp[4];
    for(long long int i=0;i<4;i++){
        dp[i].first=0;
        dp[i].second=i;
    }
    for(long long int i=0;i<n;i++){
        cin>>x>>y;
        if(x-s[0]>0){
            dp[0].first++;
        }
        if(x-s[0]<0){
            dp[1].first++;
        }
        if(y-s[1]>0){
            dp[2].first++;
        }
        if(y-s[1]<0){
            dp[3].first++;
        }
    }
    x=s[0];
    y=s[1];
    sort(dp,dp+4);
    cout<<dp[3].first<<"\n";
    if(dp[3].second==0){
        cout<<x+1<<" "<<y<<"\n";
    }
    if(dp[3].second==1){
        cout<<x-1<<" "<<y<<"\n";
    }
    if(dp[3].second==2){
        cout<<x<<" "<<y+1<<"\n";
    }
    if(dp[3].second==3){
        cout<<x<<" "<<y-1<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
   // cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}