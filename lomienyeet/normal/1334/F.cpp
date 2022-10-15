#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=5e5+5,wa=4e18;
int bit[mxN];
void upd(int x,int v){
    for(;x<mxN;x+=x&-x)bit[x]+=v;
}
int qry(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=bit[x];
    return ans;
}
int qsum(int l,int r){return qry(r)-qry(l-1);}
signed main(){
    int n;
    cin>>n;
    int arr[n+1],vis[n+1]={},weeee[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        vis[arr[i]]=1;
    }
    for(int i=1;i<=n;i++)cin>>weeee[i];
    int m;
    cin>>m;
    int pos[n+1]={},que[m+1]={};
    for(int i=1;i<=m;i++){
        cin>>que[i];
        pos[que[i]]=i;
        if(!vis[que[i]]){
            cout<<"NO\n";
            return 0;
        }
    }
    int one[n+1]={},two[n+1]={};
    for(int i=n;i>0;i--){
        if(pos[arr[i]]){
            int z=pos[arr[i]];
            one[i]=qsum(que[z-1]+1,n)+weeee[i];
            two[i]=qsum(arr[i]+1,n);
        }
        if(weeee[i]>0)upd(arr[i],weeee[i]);
    }
    int dp[n+1],mini[n+1];
    for(int i=1;i<=n;i++)dp[i]=mini[i]=wa;
    dp[0]=mini[0]=qsum(1,n);
    int ee=0;
    for(int i=1;i<=n;i++){
        if(weeee[i]<0)ee+=weeee[i];
        if(!pos[arr[i]])continue;
        int z=pos[arr[i]];
        if(mini[z-1]!=wa){
            dp[i]=min(dp[i],mini[z-1]+two[i]-one[i]);
            mini[z]=min(mini[z],dp[i]);
        }
    }
    int ans=wa;
    for(int i=1;i<=n;i++){
        if(arr[i]==que[m])ans=min(ans,dp[i]);
    }
    if(ans==wa)cout<<"NO\n";
    else cout<<"YES\n"<<ee+ans<<"\n";
}