#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 16;
int n,a[N];

int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&a[i]);
  int ok=0;
  REP(mask,1<<n) {
    int cost=0;
    REP(i,n) cost += (mask&1<<i) ? a[i] : -a[i];
    if (cost % 360 == 0) ok=1;
  }
  puts(ok ? "YES" : "NO");
}