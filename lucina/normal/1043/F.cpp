#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,maxn=3e5+10;
int n,x,cnt[maxn],f[maxn],inv[maxn],dp[maxn];
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

inline int power(int a,int b) {
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
    for(int i=1;i<maxn;i++){
        for(int j=i+i;j<maxn;j+=i){
            cnt[i]+=cnt[j];
        }
    }
    f[1]=1;f[0]=1;
    for(int i=2;i<maxn;i++){
        f[i]=mul(f[i-1],i);
    }
    for(int i=0;i<maxn;i++)
        inv[i]=power(f[i],mod-2);

    for(int i=1;i<=7;i++){
        memset(dp,0,sizeof(dp));
        for(int j=maxn-1;j>=1;j--){
            if(cnt[j]<i)continue;
            dp[j]=mul(f[cnt[j]],mul(inv[i],inv[cnt[j]-i]));
            for(int k=j+j;k<maxn;k+=j){
                dp[j]=sub(dp[j],dp[k]);
            }
        }
        if(dp[1]>0){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1");
}