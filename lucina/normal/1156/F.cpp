#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int a[5002],n,x,dp[5002][5002],inv[5002],cnt[5002],sum[5002][5002];
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

int power(int a,int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=5002;i++)
        inv[i]=power(i,mod-2);
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(cnt[i]==0||n==j){
                sum[i][j]=add(sum[i][j],sum[i+1][j]);
                continue;
            }
            dp[i][j]=add(dp[i][j],mul(cnt[i]-1,inv[n-j]));
            dp[i][j]=add(dp[i][j],mul(sum[i+1][j+1],inv[n-j]));
            sum[i][j]=add(sum[i][j],sum[i+1][j]);
            sum[i][j]=add(sum[i][j],mul(cnt[i],dp[i][j]));
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=add(ans,mul(dp[i][1],mul(cnt[i],inv[n])));
    }
    printf("%d\n",ans);

}