#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,v) for(typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define fi first
#define se second

typedef pair<int,int> PII;

// 86400

int n, k;
PII a[4040];
int F[4040][4040];

int main() {
  cin >> n >> k;
  Rep(i, n) cin >> a[i].fi >> a[i].se;
  /*srand(time(0));
  n = 4000; k = 53;
  Rep(i,n) a[i].fi = rand() % 86400 + 1, a[i].se = rand() % 10 + 1;*/
  if (n == 0 || k == n) {
    cout << 86400 << endl;
    return 0;
  }
  sort(a, a + n);
  F[0][1] = 0;
  F[0][0] = a[0].fi + a[0].se - 1;
  For(i, 1, n - 1) {
    F[i][i + 1] = 0;
    Ford(j, i, 0) {
      F[i][j] = 86400;
      if (j > 0) F[i][j] = min(F[i][j], F[i - 1][j - 1]);
      int giao = max(0, F[i - 1][j] - a[i].fi + 1);
      F[i][j] = min(F[i][j], a[i].fi + a[i].se - 1 + giao);
    }
  }
  int result = a[k].fi - 1;
  Rep(i, n) For(j, 0, i) if (j <= k) {
    int con = k - j;
    int z = i + con + 1;
    int last = (z >= n) ? 86400 : (a[z].fi - 1);
    int first = F[i][j] + 1;
    result = max(result, last - first + 1);
  }
  cout << result << endl;
  return 0;
}