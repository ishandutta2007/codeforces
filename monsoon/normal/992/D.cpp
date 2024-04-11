#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
typedef long long ll;

const int N = 200100;
const ll MAXPROD = 1e18+100;
int n,k,a[N],nxt[N];
ll ans;

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n) { scanf("%d",&a[i]); }
  nxt[n] = n;
  REPDN(i,n) { nxt[i] = a[i]>1 ? i : nxt[i+1]; }
  REP(i,n) {
    ll prod = 1, sum = 0;
    int j=i;
    while (true) {
      if (prod % k == 0) {
        ll sum2 = prod/k;
        if (sum <= sum2 && sum2 <= sum+nxt[j]-j) {
          ++ans;
        }
      }
      if (nxt[j] == n) break;
      if (prod > MAXPROD / a[nxt[j]]) break;
      prod *= a[nxt[j]];
      sum += nxt[j]-j + a[nxt[j]];
      j = nxt[j]+1;
    }
  }
  printf("%lld\n", ans);
}