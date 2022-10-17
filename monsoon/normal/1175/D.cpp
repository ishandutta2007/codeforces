#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
typedef long long ll;

const int N = 300100;
int n,k,a[N];
ll pref[N],ans;

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n) scanf("%d",&a[i]);
  pref[n] = 0;
  REPDN(i,n) { pref[i] = pref[i+1] + a[i]; }
  ans = pref[0];
  sort(pref+1, pref+n, greater<ll>());
  REP(i,k-1) { ans += pref[i+1]; }
  printf("%lld\n", ans);
}