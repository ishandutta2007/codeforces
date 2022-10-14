#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,m,k,a[N],s[N];
double ans;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        if(n-i<=m)
            ans=max(ans,1.0*(s[i]+min(i*k,m-n+i))/i);
    }
    cout<<fixed<<setprecision(8)<<ans<<"\n";
}