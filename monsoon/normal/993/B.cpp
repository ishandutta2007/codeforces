#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 20;
int n,m;
int pa[N][2],pb[N][2];
set<int> ktoa[N],ktob[N];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) REP(j,2) scanf("%d",&pa[i][j]);
  REP(i,m) REP(j,2) scanf("%d",&pb[i][j]);
  set<int> liczby;
  REP(i,n) REP(j,m) {
    REP(ii,2) REP(jj,2) if (pa[i][ii] == pb[j][jj] && pa[i][1-ii] != pb[j][1-jj]) {
      liczby.insert(pa[i][ii]);
      ktoa[i].insert(pa[i][ii]);
      ktob[j].insert(pa[i][ii]);
    }
  }
  if (liczby.size()==1) {
    printf("%d\n",*liczby.begin());
  } else {
    int ok=1;
    REP(i,n) if (ktoa[i].size() >= 2) ok=0;
    REP(i,m) if (ktob[i].size() >= 2) ok=0;
    printf("%d\n", ok ? 0 : -1);
  }
}