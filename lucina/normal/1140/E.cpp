#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int n,k,u;
int a[maxn];
int dp[2][maxn][2];
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int pow(int a,int b) {
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
int solve(int x){
    bool z=true; int cnt=0,ans=1;
    for(int j=x;j<=n;j+=2)
        z&=(a[j]==-1),cnt++;
    if(z) return mul(k,pow(k-1,cnt-1));
    cnt=0;int la=a[x];
    for(int j=x;j<=n;j+=2){
        if(a[j]!=-1){
            if(la!=-1)
           ans=mul(ans,dp[la==a[j]?0:1][cnt][1]);
            else ans=mul(ans,pow(k-1,cnt));
           la=a[j],cnt=0;
        }
        else
            cnt++;
    }
    if(cnt) ans=mul(ans,pow(k-1,cnt));
    return ans;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=1;j<=2;j++)
    for(int i=j;i<=n-2;i++){
        if(a[i]!=-1&&a[i]==a[i+2])
            return printf("0"),0;
    }
    dp[1][0][1]=1,dp[0][0][1]=1;
    /*dp[i][0]==left end dp[i][1]!=left end*/
    dp[0][1][0]=0;dp[0][1][1]=k-1;dp[1][1][0]=1;dp[1][1][1]=k-2;
    for(int i=2;i<=n/2+1;i++){
        dp[0][i][0]=dp[0][i-1][1];
        dp[0][i][1]=add(mul(dp[0][i-1][0],k-1),mul(dp[0][i-1][1],k-2));
        dp[1][i][0]=dp[1][i-1][1];
        dp[1][i][1]=add(mul(dp[1][i-1][0],k-1),mul(dp[1][i-1][1],k-2));
    }
    int ans=solve(1);
    ans=mul(ans,solve(2));
    printf("%d\n",ans);
}