#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 1100, DR[] = {-1,1,0,0}, DC[] = {0,0,-1,1};
int rows,cols;
char b[N][N];
int comp[N][N],size[N*N],C;

void dfs(int r, int c) {
  comp[r][c] = C;
  size[C]++;
  REP(m,4) {
    int nr = r + DR[m], nc = c + DC[m];
    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
    if (b[nr][nc] == '*' || comp[nr][nc] != -1) continue;
    dfs(nr,nc);
  }
}

int main() {
  scanf("%d%d",&rows,&cols);
  REP(r,rows) scanf("%s",b[r]);
  memset(comp,-1,sizeof(comp));
  REP(r,rows) REP(c,cols) if (b[r][c] == '.' && comp[r][c]==-1) {
    dfs(r,c); ++C;
  }

  REP(r,rows) REP(c,cols) if (b[r][c] == '*') {
    int si = 1;
    set<int> comps;
    REP(m,4) {
      int nr = r + DR[m], nc = c + DC[m];
      if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
      if (b[nr][nc] != '.') continue;
      comps.insert(comp[nr][nc]);
    }
    FORE(i,comps) si += size[*i];
    b[r][c] = '0' + (si%10);
  }
  REP(r,rows) puts(b[r]);
}