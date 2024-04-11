#include <iostream>

using namespace std;

int A[3][100010];

int main() {
  string S; cin >> S;
  int N = S.size();

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < N; j++) {
      A[i][j + 1] = A[i][j] + (S[j] == 'x' + i);
    }
  }

  int M; cin >> M;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--;

    int mn = N, mx = -1;
    for(int j = 0; j < 3; j++) {
      mn = min(mn, A[j][b] - A[j][a]);
      mx = max(mx, A[j][b] - A[j][a]);
    }
    if(b - a <= 2 || mx - mn <= 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}