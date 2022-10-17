#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int C = 30;
ll n,sum;
int _,m,ans;
int cnt[C];

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%lld%d",&n,&m);
    sum = 0;
    ans = 0;
    REP(i,C) cnt[i] = 0;
    REP(i,m) {
      int a; scanf("%d",&a);
      sum += a;
      int log = __builtin_ctz(a);
      cnt[log]++;
    }
    if (sum < n) {
      puts("-1");
      continue;
    }
    while (n) {
      if (n&1) {
        int idx=0;
        while (!cnt[idx]) {
          cnt[idx++]++;
          ++ans;
        }
        cnt[idx]--;
      }
      n /= 2;
      int jed = cnt[0];
      REP(i,C-1) cnt[i] = cnt[i+1];
      cnt[0] += jed/2;
      cnt[C-1] = 0;
    }
    printf("%d\n",ans);
  }
}