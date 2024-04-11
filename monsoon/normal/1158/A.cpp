#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
typedef long long ll;

const int N = 100100;
int n,m,a[N],b[N];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) { scanf("%d",&a[i]); }
  REP(i,m) { scanf("%d",&b[i]); }
  sort(a,a+n);
  sort(b,b+m);
  if (a[n-1] > b[0]) {
    puts("-1"); return 0;
  }
  ll ans = 0;
  REP(i,n) { ans += ll(m) * a[i]; }
  if (a[n-1] == b[0]) {
    REP(i,m) { ans += b[i] - a[n-1]; }
  } else {
    if (n == 1 || m == 1) {
      puts("-1"); return 0;
    }
    FOR(i,1,m) { ans += b[i] - a[n-1]; }
    ans += b[0] - a[n-2];
  }
  printf("%lld\n", ans);
}