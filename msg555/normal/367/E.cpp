#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int N, M, target;

int DP1[2][400][400][2][2];
int DP2[2][400][400][2];

int main() {
  cin >> N >> M >> target;
  target--;

  if (N <= M) for(int nxt = M; nxt >= 0; nxt--) {
    for(int x = N; x >= 0; x--) {
      for(int y = N; y >= x; y--) {
        for(int hx = 0; hx < 2; hx++) {
          int& ref = DP2[nxt & 1][x][y][hx];
          if(x == N && y == N) {
            ref = hx;
            continue;
          } else if(nxt == M) {
            ref = 0;
            continue;
          }

          ref = DP2[~nxt & 1][x][y][hx];
          ref += DP2[~nxt & 1][x + 1][y + 1][hx || nxt == target];
          ref %= MOD;
          ref += DP2[~nxt & 1][x][y + 1][hx || nxt == target];
          ref %= MOD;
          if(x < y) {
            ref += DP2[~nxt & 1][x + 1][y][hx];
            ref %= MOD;
          }
        }
      }
    }
  }

  int res = DP2[0][0][0][0];
  for(int i = 1; i <= N; i++) {
    res = (1ll * res * i) % MOD;
  }
  cout << res << endl;
  return 0;
}