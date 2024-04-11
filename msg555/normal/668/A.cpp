#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> V(N * M, 0);
  vector<vector<int> > A(N, vector<int>(M));
  for (int i= 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      A[i][j] = i * M + j;
    }
  }

  for (int i = 0; i < Q; i++) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      int r; cin >> r; r--;
      for (int j = 0; j + 1 < M; j++) {
        swap(A[r][j], A[r][j + 1]);
      }
    } else if (cmd == 2) {
      int c; cin >> c; c--;
      for (int j = 0; j + 1 < N; j++) {
        swap(A[j][c], A[j + 1][c]);
      }
    } else {
      int r, c, v;
      cin >> r >> c >> v; r--; c--;
      V[A[r][c]] = v;
    }
  }

  for (int i= 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (j) cout << ' ';
      cout << V[i * M + j];
    }
    cout << '\n';
  }

  return 0;
}