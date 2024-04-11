#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int a[6],y,ans;

int main() {
  REP(i,6) scanf("%d",&a[i]);
  y += a[0];
  REP(i,a[1]) { ans += 2*y+1; ++y; }
  REP(i,a[2]) { ans += 2*y; }
  y -= a[3];
  REP(i,a[4]) { --y; ans -= 2*y+1; }
  REP(i,a[5]) { ans -= 2*y; }
  printf("%d\n", ans);
}