#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 300100;
int n, a[N], pref[N], parit[N];
ll answer;

int main() {
  scanf("%d",&n);
  REP(i,n) {
    ll ax;
    scanf("%lld",&ax);
    a[i] = __builtin_popcountll(ax);
    pref[i+1] = pref[i] + a[i];
    parit[i+1] = parit[i] + (pref[i+1] % 2 == 0);
  }
  REP(i,n) {
    int sum = 0, mx = 0, j;
    for (j = i; j < n; ++j) {
      if (sum >= 125) break;
      sum += a[j];
      mx = max(mx, a[j]);
      if (sum >= 2*mx && sum % 2 == 0) ++answer;
    }
    int rest = (pref[i] % 2 == 0) ? (parit[n] - parit[j]) : (n - j) - (parit[n] - parit[j]);
    answer += rest;
  }

  printf("%lld\n", answer);
}