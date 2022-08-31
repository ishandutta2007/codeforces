#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string A[45];

int SM[45][45];
int DP[45][45][45][45];

int main() {
  int N, M, Q; cin >> N >> M >> Q;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      SM[i + 1][j + 1] = (A[i][j] == '1') + SM[i + 1][j] +
                                            SM[i][j + 1] - SM[i][j];
    }
  }
  for(int a = N - 1; a >= 0; a--) {
    for(int b = M - 1; b >= 0; b--) {
      for(int c = a + 1; c <= N; c++) {
        for(int d = b + 1; d <= M; d++) {
          DP[a][b][c][d] = SM[c][d] - SM[a][d] - SM[c][b] + SM[a][b] == 0;
          DP[a][b][c][d] += DP[a + 1][b][c][d] + DP[a][b + 1][c][d] +
                            DP[a][b][c - 1][d] + DP[a][b][c][d - 1];
          DP[a][b][c][d] -= DP[a + 1][b + 1][c][d] + DP[a + 1][b][c - 1][d] +
                            DP[a + 1][b][c][d - 1] + DP[a][b + 1][c - 1][d] +
                            DP[a][b + 1][c][d - 1] + DP[a][b][c - 1][d - 1];
          DP[a][b][c][d] += DP[a + 1][b + 1][c - 1][d] +
                            DP[a + 1][b + 1][c][d - 1] +
                            DP[a + 1][b][c - 1][d - 1] +
                            DP[a][b + 1][c - 1][d - 1];
          DP[a][b][c][d] -= DP[a + 1][b + 1][c - 1][d - 1];
        }
      }
    }
  }
  for(int i = 0; i < Q; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--;
    cout << DP[a][b][c][d] << '\n';
  }
  return 0;
}