#include <iostream>
#include <vector>

using namespace std;

int mtweak(int x, int M) {
  if (x < 0) return x + M;
  if (x >= M) return x - M;
  return x;
}

int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);

  int se = 0;
  int so = 0;
  for (int i = 0; i < Q; i++) {
    int cmd; scanf("%d", &cmd);
    if (cmd == 1) {
      int v; scanf("%d", &v);
      se += v;
      so += v;
    } else {
      if (se % 2) {
        se--;
        so++;
      } else {
        se++;
        so--;
      }
    }
    se = mtweak(se, N);
    so = mtweak(so, N);
  }

  vector<int> A(N, -1);
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      A[mtweak(i + se, N)] = i;
    } else {
      A[mtweak(i + so, N)] = i;
    }
  }

  for (int i = 0; i < N; i++) {
    if (i) cout << ' ';
    cout << A[i] + 1;
  }
  cout << endl;

  return 0;
}