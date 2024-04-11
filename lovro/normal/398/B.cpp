#define NDEBUG
#include <cstdio>
#include <iostream>
#include <unordered_set>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)

int main() {
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  unordered_set<int> haver, havec;
  repeat (m) {
    int y, x;
    cin >> y >> x;
    haver.insert(y);
    havec.insert(x);
  }

  static long double dp[2002][2002];
  for (int nr=n; nr>=0; --nr) {
    for (int nc=n; nc>=0; --nc) {
      if (nr == n && nc == n) {
        dp[nr][nc] = 0.0;
        continue;
      }

      long double e = n*n;
      e += nr * (n-nc) * dp[nr][nc+1];
      e += (n-nr) * nc * dp[nr+1][nc];
      e += (n-nr) * (n-nc) * dp[nr+1][nc+1];
      e /= n*n - nr*nc;
      dp[nr][nc] = e;
    }
  }

  printf("%.10f\n", double(dp[haver.size()][havec.size()]));
  return 0;
}