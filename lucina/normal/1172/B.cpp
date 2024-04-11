#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
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
int n,u,v,f[maxn],deg[maxn];
vector<int> a[maxn];
int main(){
    f[0]=1;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        f[i]=mul(f[i-1],i);
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
    }
    f[n]=mul(f[n-1],n);
    int ans=n;
    for(int i=1;i<=n;i++)
        ans=mul(ans,f[deg[i]]);
    printf("%d\n",ans);
}