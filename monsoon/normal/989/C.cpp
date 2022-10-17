#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 52;
int a,b,c,d,n;
char t[N][N];
int gr,gc;

void go(int num, char c) {
  REP(i,num) {
    t[gr][gc] = c;
    gc += 2;
    if (gc >= n) { gr += 2; gc = 1; }
  }
}

int main() {
  scanf("%d%d%d%d",&a,&b,&c,&d);
  n = 50;
  REP(r,n) REP(c,n) t[r][c] = r<n/2 ? 'A' : 'B';
  --a; --b;
  gr=1; gc=1;
  go(b, 'B');
  go(c, 'C');
  gr=n/2+1; gc=1;
  go(a, 'A');
  go(d, 'D');
  printf("%d %d\n", n, n);
  REP(r,n) puts(t[r]);
}