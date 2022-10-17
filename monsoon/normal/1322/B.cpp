#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 500100;
int n,a[N];
int ns[2],as[2][N];

int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&a[i]);
  int ans = 0;
  REP(k,25) {
    int mask = (1<<k)-1;
    REP(t,2) ns[t] = 0;
    REP(i,n) {
      int t=(a[i]>>k)&1;
      as[t][ns[t]++] = a[i] & mask;
    }

    int cnt = 0;
    REP(t,2) sort(as[t],as[t]+ns[t]);
    REP(t,2) {
      REP(i,ns[t]) {
        int x = as[t][i];
        int pos = lower_bound(as[t]+i+1,as[t]+ns[t],(1<<k)-x) - as[t];
        cnt += ns[t]-pos;
        if (t==0) {
          pos = upper_bound(as[t^1],as[t^1]+ns[t^1],(1<<k)-x-1) - as[t^1];
          cnt += pos;
        }
      }
    }
    ans |= (cnt&1) << k;
  }
  printf("%d\n",ans);
}