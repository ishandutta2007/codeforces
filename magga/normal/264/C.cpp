#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,q,a,b;cin>>n>>q;
    long long int arr[n+1];
    int col[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)cin>>col[i];
    int m1,m2;
    long long int dp[n+2];
    bool flag[n+2];
    long long int ans = 0;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        ans=0;
        m1=0;m2=n+1;
        for(int i=0;i<=n+1;i++){dp[i]=-1e12;flag[i]=0;}
        dp[0]=0;dp[n+1]=0;
        for(int i=1;i<=n;i++){
            if(flag[col[i]])
                dp[col[i]]=max(dp[col[i]],dp[col[i]]+a*arr[i]);
            if(col[i]==m1)    
                dp[col[i]]=max(dp[col[i]],dp[m2]+b*arr[i]);
            else
                dp[col[i]]=max(dp[col[i]],dp[m1]+b*arr[i]);
            flag[col[i]]=1;
            if(dp[col[i]]>dp[m1] && m1!=col[i]){
                m2=m1;
                m1=col[i];
            }else if( dp[col[i]] > dp[m2] && m1!=col[i] ){
                //cout<< dp[col[i]]<<" "<<dp[m2]<<"\n";
                m2=col[i];
            }
            //cout<<dp[col[i]]<<" "<<m1<<" "<<m2<<" "<<col[i]<<"\n";
            ans=max(ans,dp[col[i]]);
        }
         cout<<ans<<"\n";
    }
   
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