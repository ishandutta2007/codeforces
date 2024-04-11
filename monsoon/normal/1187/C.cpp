#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
int n,m,t[N],l[N],r[N],sor[N];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,m) { scanf("%d%d%d",&t[i],&l[i],&r[i]); --l[i]; }
  REP(i,m) if (t[i] == 1) {
    for(int j=l[i]; j<r[i]-1; ++j) { sor[j]=1; }
  }
  REP(i,m) if (t[i] == 0) {
    int fnd=0;
    for(int j=l[i]; j<r[i]-1; ++j) if (!sor[j]) fnd=1;
    if (!fnd) { puts("NO"); return 0; }
  }
  puts("YES");
  int x=n+1;
  REP(i,n) {
    printf("%d ",x);
    x = x+sor[i]-1;
  }
  printf("\n");
}