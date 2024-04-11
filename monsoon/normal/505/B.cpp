#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110;
int n,m,fu[N][N],q;

int fufind(int c, int i) { return fu[c][i] < 0 ? i : fu[c][i] = fufind(c, fu[c][i]); }
void fujoin(int c, int i, int j) {
  i = fufind(c, i);
  j = fufind(c, j);
  if (i != j) { fu[c][i] = j; }
}

int main() {
  scanf("%d%d",&n,&m);
  REP(c,m) REP(i,n) fu[c][i] = -1;
  REP(i,m) {
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    fujoin(--c, --a, --b);
  }
  scanf("%d",&q);
  REP(i,q) {
    int a,b,ans=0; scanf("%d%d",&a,&b); --a; --b;
    REP(c,m) {
      if (fufind(c,a) == fufind(c,b)) ++ans;
    }
    printf("%d\n", ans);
  }
}