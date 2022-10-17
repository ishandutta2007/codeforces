#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,n) for(int i=(a);i<(n);++i)

const int N = 3100, infty = 1000000000;
int n,s[N],c[N],ans;

int main() {
  scanf("%d",&n);
  ans = infty;
  REP(i,n) scanf("%d",&s[i]);
  REP(i,n) scanf("%d",&c[i]);
  REP(i,n) {
    int j1 = -1, j2 = -1;
    REP(j,i) if (s[j] < s[i] && (j1 == -1 || c[j] < c[j1])) { j1 = j; }
    FOR(j,i+1,n) if (s[i] < s[j] && (j2 == -1 || c[j] < c[j2])) { j2 = j; }
    if (j1 != -1 && j2 != -1) {
      ans = min(ans, c[j1] + c[i] + c[j2]);
    }
  }
  if (ans == infty) puts("-1");
  else printf("%d\n", ans);
}