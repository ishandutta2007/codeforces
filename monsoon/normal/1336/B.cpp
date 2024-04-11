#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 100100;
int _,n[3],a[3][N];
ll ans;

ll sq(int x) { return ll(x)*x; }

ll calc(int i0, int i1, int i2) {
  return sq(i0 - i1) + sq(i0 - i2) + sq(i1 - i2);
}

int main() {
  scanf("%d",&_);
  while (_-->0) {
    scanf("%d%d%d",&n[0],&n[1],&n[2]);
    REP(k,3) REP(i,n[k]) scanf("%d",&a[k][i]);
    REP(k,3) sort(a[k],a[k]+n[k]);

    ans = calc(a[0][0], a[1][0], a[2][0]);

    REP(f0,3) {
      int f1 = (f0+1)%3, f2 = (f0+2)%3;
      REP(i,n[f0]) {
        int v = a[f0][i];
        int p1 = lower_bound(a[f1],a[f1]+n[f1],v)-a[f1];
        int p2 = lower_bound(a[f2],a[f2]+n[f2],v)-a[f2];
        REP(_i1,3) REP(_i2,3) {
          int i1 = p1+_i1-1;
          int i2 = p2+_i2-1;
          if (0 <= i1 && i1 < n[f1] && 0 <= i2 && i2 < n[f2]) {
            ans = min(ans, calc(v, a[f1][i1], a[f2][i2]));
          }
        }
      }
    }
    printf("%lld\n",ans);
  }
}