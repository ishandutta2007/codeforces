#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353 ;
int n,b[maxn],c[maxn];
long long a[maxn];
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

int pow(int a,int b) {
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
long long calc(int x){
    return ((1ll*n*(n+1)/2)-(1ll*(x-1)*x/2)-(1ll*(n-x)*(n-x+1)/2));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        a[i]=(a[i]*calc(i));
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    reverse(b+1,b+1+n);
    for(int i=1;i<=n;i++)
        c[i]=(a[i]%mod);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=add(ans,mul(c[i],b[i]));
    }
    printf("%d\n",ans);
}