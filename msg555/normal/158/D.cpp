#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int A[20000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int res = accumulate(A, A + N, 0);
  for(int f = 3; f <= N; f++) {
    if(N % f) continue;

    int m = N / f;
    for(int i = 0; i < m; i++) {
      int s = 0;
      for(int j = 0; j < f; j++) s += A[i + j * m];
      res = max(s, res);
    }
  }
  cout << res << endl;
}