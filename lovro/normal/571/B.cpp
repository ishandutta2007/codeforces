#define NDEBUG
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

template<typename T, typename U> inline bool makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
    return true;
  }
  return false;
}
typedef long long int64;
#define ALL(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<int> v(N);
  for (auto& x : v) {
    cin >> x;
  }
  sort(ALL(v));

  const int64 INF = numeric_limits<int64>::max() / 4;
  const int MAXD = N%K;
  const int G = N/K;
  static int64 dp[5001][5001];
  for (int a=MAXD; a>=0; --a) {
    for (int b=K-MAXD; b>=0; --b) {
      if (a == MAXD && b == K-MAXD) {
        dp[a][b] = 0;
        continue;
      }

      dp[a][b] = INF;
      const int pos = a * (G+1) + b * G;
      if (a < MAXD) {
        makemin(dp[a][b], dp[a+1][b] + v[pos+G] - v[pos]);
      }
      if (b < K-MAXD) {
        makemin(dp[a][b], dp[a][b+1] + v[pos+G-1] - v[pos]);
      }
    }
  }
  cout << dp[0][0] << '\n';
}