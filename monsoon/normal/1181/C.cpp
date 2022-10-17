#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
typedef long long ll;

const int N = 1100;
int rows,cols;
char b[N][N];
int h[N][N];
int hei[N],wid[N],pos[N];
int hei_dn[N],hei_up[N];
ll ans;

int main() {
  scanf("%d%d",&rows,&cols);
  REP(r,rows) scanf("%s",b[r]);
  REP(r,rows) {
    REPDN(c,cols) h[r][c] = b[r][c] == b[r][c+1] ? 1 + h[r][c+1] : 1;
  }

  REP(c,cols) {
    int k = 0;
    REP(r,rows) {
      int r2 = r+1, hh = h[r][c];
      while (r2 < rows && b[r][c] == b[r2][c]) {
        hh = min(hh, h[r2][c]);
        ++r2;
      }
      hh = cols+1;
      REP(_i,r2-r) {
        int i = r+_i;
        hh = min(hh, h[i][c]);
        hei_dn[i] = hh;
      }
      hh = cols+1;
      REP(_i,r2-r) {
        int i = r2-1-_i;
        hh = min(hh, h[i][c]);
        hei_up[i] = hh;
      }

      pos[k] = r;
      hei[k] = hh;
      wid[k] = r2-r;
      ++k;
      r = r2-1;
    }

    FOR(r,1,k-1) if (min(wid[r-1], wid[r+1]) >= wid[r]) {
      int hei_a = hei_up[pos[r] - wid[r]];
      int hei_b = hei_dn[pos[r] + 2*wid[r]-1];
      ans += min(min(hei_a, hei_b), hei[r]);
    }
  }
  printf("%lld\n",ans);
}