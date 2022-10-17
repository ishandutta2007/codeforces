#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N = 200100;
int n,a[2*N];

int main() {
  scanf("%d",&n);
  REP(i,2*n) scanf("%d",&a[i]);
  sort(a,a+2*n);
  ll ans = ll(a[n-1]-a[0]) * (a[2*n-1]-a[n]);
  REP(i,n) {
    ll cost = ll(a[2*n-1]-a[0]) * (a[i+n-1]-a[i]);
    ans = min(ans, cost);
  }
  printf("%lld\n",ans);
}