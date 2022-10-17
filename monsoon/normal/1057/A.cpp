#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 200100;
int n,p[N],ans[N],a;

int main() {
  scanf("%d",&n);
  REP(i,n-1) { scanf("%d",&p[i+1]); --p[i+1]; }
  ans[a++] = n-1;
  while (ans[a-1] != 0) { ans[a] = p[ans[a-1]]; a++; }
  REP(i,a) { printf("%d ", ans[a-1-i]+1); }
  printf("\n");
}