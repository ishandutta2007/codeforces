#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 210000;
const ll infty = 1000000000LL*1000000000;
int n,m,ta,tb,k;
ll a[N],b[N],ans;

int main() {
  scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
  REP(i,n) { scanf("%lld",&a[i]); }
  REP(i,m) { scanf("%lld",&b[i]); }
  a[n] = infty/2;
  b[m] = infty;
  REP(i,n+1) if (i <= k) {
    ll tim = a[i] + ta;
    int pos = lower_bound(b, b+m+1, tim) - b;
    int pocz = min(m+1, pos+k-i);
    ans = max(ans, b[pocz] + tb);
  }
  if (ans >= infty) { ans = -1; }
  printf("%lld\n",ans);
}