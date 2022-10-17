#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
const int DI[] = {-1,1,0,0}, DJ[] = {0,0,-1,1};
int rows,cols;
char b[N][N];

void dfs(int i, int j) {
  b[i][j] = 'X';
  REP(m,4) {
    int ni = i + DI[m], nj = j + DJ[m];
    if (ni < 0 || nj < 0 || ni >= rows || nj >= cols) continue;
    if (b[ni][nj] != '#') continue;
    dfs(ni, nj);
  }
}

int main() {
  scanf("%d%d",&rows,&cols);
  REP(i,rows) scanf("%s",b[i]);
  int ok = 1;

  int fr = 0;
  REP(i,rows) {
    int was = 0, wasn = 0;
    REP(j,cols) {
      if (b[i][j] == '#' && wasn) ok = 0;
      if (b[i][j] == '#') was = 1;
      if (b[i][j] == '.' && was) wasn = 1;
    }
    if (!was) fr = 1;
  }
  int fc = 0;
  REP(j,cols) {
    int was = 0, wasn = 0;
    REP(i,rows) {
      if (b[i][j] == '#' && wasn) ok = 0;
      if (b[i][j] == '#') was = 1;
      if (b[i][j] == '.' && was) wasn = 1;
    }
    if (!was) fc = 1;
  }
  if (fr ^ fc) { ok = 0; }

  int cnt = 0;
  REP(i,rows) REP(j,cols) if (b[i][j] == '#') { dfs(i,j); ++cnt; }

  if (!ok) cnt = -1;
  printf("%d\n",cnt);
}