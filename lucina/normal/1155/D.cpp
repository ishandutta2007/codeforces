#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,a[maxn];
long long dp[2][maxn],f[maxn],ans,sum;

int read(){
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}
int main(){
    n=read();x=read();
    for(int i=1;i<=n;i++)
    a[i]=read();
    for(int i=1;i<=n;i++){
        dp[0][i]=a[i];
        dp[0][i]=max(dp[0][i-1]+a[i],dp[0][i]);
    }
    for(int i=n;i>=1;i--){
        dp[1][i]=a[i];
        dp[1][i]=max(dp[1][i+1]+a[i],dp[1][i]);
    }
    for(int i=1;i<=n;i++){
        f[i]=max({dp[0][i-1],f[i-1],0ll})+(1ll*a[i]*x);
        ans=max(ans,f[i]+max(0ll,dp[1][i+1]));
    }
    ans=max(ans,dp[0][n]);
    printf("%lld\n",ans);
}