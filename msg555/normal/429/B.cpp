#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int A[1010][1010];
int V[4][1010][1010];

int TMP[1010][1010];

void rot(int X[1010][1010]) {
  swap(N, M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      TMP[i][j] = X[j][N - i - 1];
    }
  }
  memcpy(X, TMP, sizeof(TMP));
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  for(int rt = 0; rt < 4; rt++) {
    for(int i = 0; i < rt; i++) {
      rot(A);
    }
    for(int i = N - 1; i >= 0; i--) {
      for(int j = M - 1; j >= 0; j--) {
        V[rt][i][j] = A[i][j] + max(V[rt][i + 1][j], V[rt][i][j + 1]);
      }
    }
    for(int i = rt; i < 4; i++) {
      rot(V[rt]);
      swap(N, M);
      rot(A);
    }
  }

  int result = 0;
  for(int i = 1; i + 1 < N; i++) {
    for(int j = 1; j + 1 < M; j++) {
      result = max(result,
                   V[2][i - 1][j] + V[0][i + 1][j] +
                   V[1][i][j - 1] + V[3][i][j + 1]);
      result = max(result,
                   V[2][i][j - 1] + V[0][i][j + 1] +
                   V[1][i + 1][j] + V[3][i - 1][j]);
    }
  }
  cout << result << endl;

  return 0;
}