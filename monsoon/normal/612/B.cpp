#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 200100;
int n,a[N],arev[N];
ll ans;

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); --a[i]; }
  REP(i,n) { arev[a[i]] = i; }
  REP(i,n-1) { ans += abs(arev[i+1] - arev[i]); }
  printf("%lld\n", ans);
}