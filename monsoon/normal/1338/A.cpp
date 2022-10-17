#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110000;
int _,n,a[N];

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d",&n);
    REP(i,n) { scanf("%d",&a[i]); }
    int last = a[0], ma = 0;
    REP(i,n) {
      if (last > a[i]) { ma = max(ma, last-a[i]); }
      last = max(last, a[i]);
    }
    int ans = 0;
    while (ma > 0) {
      ma -= 1<<ans;
      ++ans;
    }
    printf("%d\n",ans);
  }
}