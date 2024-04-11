#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int n,m,arr[mxN],bit[mxN<<2]; // Do not.
void upd(int x){
    for(;x<mxN<<2;x+=x&-x)bit[x]++;
}
int qry(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=bit[x];
    return ans;
}
int eat(int x){
    memset(bit,0,sizeof bit);
    int dt[n+1]={},ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i]<=x)dt[i]=1;
        else dt[i]=-1;
        dt[i]+=dt[i-1];
    }
    upd(n+1);
    for(int i=1;i<=n;i++){
        ans+=qry(dt[i]+n+1);
        upd(dt[i]+n+1);
    }
    return ans;
}
signed main(){
    // uh, i have done the general case edition of this problem.
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    cout<<eat(m)-eat(m-1)<<"\n";
}