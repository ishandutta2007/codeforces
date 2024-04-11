#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

const int N = 100100;
int n,ile[2],ileb[2];
char a[N],b[N];

int main() {
  scanf("%d%s%s",&n,a,b);
  REP(i,n) {
    if (b[i] == '1') ileb[a[i]-'0']++;
    ile[a[i]-'0']++;
  }
  ll ans = ll(ile[0]) * ile[1] - ll(ileb[0]) * ileb[1];
  printf("%lld\n", ans);
}