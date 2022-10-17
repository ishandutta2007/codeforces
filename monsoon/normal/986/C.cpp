#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int M=1<<22;
int n,m,qe,qb,q[2*M],ans;
char vis[2*M];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,m) {
    int a; scanf("%d",&a);
    vis[a*2+1] = 2;
  }
  REP(i,1<<n) if (vis[i*2+1] == 2) {
    qe=qb=0;
    ++ans;
    vis[i*2+1] = 1;
    int msk = ((1<<n)-1-i)*2;
    if (!vis[msk]) { vis[ q[qe++] = msk ] = 1; }
    while (qe!=qb) {
      int v = q[qb++];
      if (vis[v+1] == 2) {
        vis[v+1] = 1;
        int msk = ((1<<n)-1)*2-v;
        if (!vis[msk]) { vis[ q[qe++] = msk ] = 1; }
      }
      REP(j,n) if ((v & 1<<j+1) && !vis[v-(1<<j+1)]) {
        vis[ q[qe++] = v-(1<<j+1) ] = 1;
      }
    }
  }
  printf("%d\n", ans);
}