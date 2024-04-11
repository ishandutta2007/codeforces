#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110;
int n,p,q,k,kans;
char s[N],ans[2*N];

int main() {
  scanf("%d%d%d%s",&n,&p,&q,s);
  REP(i,n+1) REP(j,n+1) if (i*p + j*q == n) {
    printf("%d\n", i+j);
    REP(_,i) { REP(__,p) ans[kans++] = s[k++]; ans[kans++] = '\n'; }
    REP(_,j) { REP(__,q) ans[kans++] = s[k++]; ans[kans++] = '\n'; }
    printf("%s", ans);
    return 0;
  }
  puts("-1");
}