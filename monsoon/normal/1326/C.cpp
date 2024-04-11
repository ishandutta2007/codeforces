#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 210000, MOD = 998244353;
int n,k,a[N];

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n) {
    scanf("%d",&a[i]);
  }
  int last = -1, ans = 1;
  long long A = 0;
  REP(i,n) if (a[i] >= n-k+1) {
    A += a[i];
    if (last != -1) {
      ans = (long long)ans * (i-last) % MOD;
    }
    last = i;
  }
  printf("%lld %d\n",A,ans);
}