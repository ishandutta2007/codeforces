#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N=110, DR[]={-1,1,0,0,-1,-1,1,1}, DC[]={0,0,-1,1,1,-1,1,-1};
int rows,cols;
char b[N][N];

bool test() {
  REP(r,rows) REP(c,cols) if (b[r][c] != '*') {
    int num_map = b[r][c] == '.' ? 0 : b[r][c]-'0';
    int num=0;
    REP(mo,8) {
      int rx = r+DR[mo], cx = c+DC[mo];
      if (rx<0 || cx<0 || rx>=rows || cx>=cols) continue;
      if (b[rx][cx] == '*') ++num;
    }
    if (num != num_map) return 0;
  }
  return 1;
}

int main() {
  scanf("%d%d",&rows,&cols);
  REP(r,rows) scanf("%s",b[r]);
  puts(test() ? "YES" : "NO");
}