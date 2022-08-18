#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M, C;
  cin >> N >> M >> C;

  vector<int> L, R;
  for (; L.size() + R.size() < N; ) {
    int p; cin >> p;
    p--;

    vector<int>& A = p < C / 2 ? L : R;
    if (p >= C / 2) p = -p;

    int ind = upper_bound(A.begin(), A.end(), p) - A.begin();
    if (ind == A.size()) {
      A.push_back(p);
    } else {
      A[ind] = p;
    }

    if (p >= 0) {
      cout << ind + 1 << endl;
    } else {
      cout << N - ind << endl;
    }
  }
  return 0;
}