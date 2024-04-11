#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 510, DX[] = {-1,1,0,0}, DY[] = {0,0,-1,1};
int rows,cols,cnt,gok;
char b[N][N];

int main() {
  scanf("%d%d",&rows,&cols);
  REP(i,rows) scanf("%s",b[i]);
  REP(i,rows) REP(j,cols) cnt += b[i][j] == '*';
  REP(i,rows) REP(j,cols) if (b[i][j] == '*') {
    int c = cnt-1, ok = 1;
    REP(m,4) {
      int l=0;
      while (true) {
        int ni = i+DX[m]*(l+1), nj = j+DY[m]*(l+1);
        if (ni < 0 || nj < 0 || ni >= rows || nj >= cols) break;
        if (b[ni][nj] == '.') break;
        ++l;
      }
      if (l == 0) ok = 0;
      c -= l;
    }
    if (c != 0) ok = 0;
    gok |= ok;
  }
  puts(gok ? "YES" : "NO");
}