#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5;
int n,p,k,arr[mxN],idx[mxN],mat[mxN][8],dp[mxN][256];
bool cmp(int a,int b){
    return arr[a]>arr[b];
}
int eat(int pos,int msk,int dep){
    if(pos==n+1)return (dep==p?0:-1e18);
    if(dp[pos][msk]!=-1)return dp[pos][msk];
    int ans=eat(pos+1,msk,dep);
    if(pos-dep-1<k)ans+=arr[idx[pos]];
    for(int i=0;i<p;i++){
        if(!(msk&(1<<i)))ans=max(ans,eat(pos+1,msk|(1<<i),dep+1)+mat[idx[pos]][i]);
    }
    return dp[pos][msk]=ans;
}
signed main(){
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++)idx[i]=i;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<p;j++)cin>>mat[i][j];
    }
    sort(idx+1,idx+n+1,cmp);
    memset(dp,-1,sizeof dp);
    cout<<eat(1,0,0)<<"\n";
}