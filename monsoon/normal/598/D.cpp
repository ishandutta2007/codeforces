#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
const int DR[] = {-1,1,0,0}, DC[] = {0,0,-1,1};
int rows,cols,q;
char b[N][N];
int comp[N][N],cnt[N*N],C;
int qe,qb,que[N*N];

int main() {
  scanf("%d%d%d",&rows,&cols,&q);
  REP(i,rows) scanf("%s",b[i]);

  REP(r,rows) REP(c,cols) comp[r][c] = -1;
  REP(r,rows) REP(c,cols) if (b[r][c] == '.' && comp[r][c] == -1) {
    qe=qb=0;
    que[qe++] = r*cols + c;
    comp[r][c] = C;
    while (qe != qb) {
      int rr = que[qb]/cols, cc = que[qb]%cols; qb++;
      REP(i,4) {
        int nr = rr+DR[i], nc = cc+DC[i];
        if (b[nr][nc] == '*') ++cnt[C];
        else if (comp[nr][nc] == -1) {
          que[qe++] = nr*cols + nc;
          comp[nr][nc] = C;
        }
      }
    }
    ++C;
  }

  REP(i,q) {
    int r,c; scanf("%d%d",&r,&c); --r; --c;
    printf("%d\n", cnt[comp[r][c]]);
  }
}