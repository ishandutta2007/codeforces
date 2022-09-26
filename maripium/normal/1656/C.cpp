#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N); for (int &a : A) cin >> a;
    sort(A.begin(), A.end());
    N = unique(A.begin(), A.end()) - A.begin(); 
    bool has1 = false;
    for (int a : A) has1 |= (a == 1);
    if (!has1) {
      cout << "YES\n";
    } else {
      bool fail = false;
      for (int i = 0; i < N - 1; ++i) if (A[i] + 1 == A[i + 1]) {
        fail = true;
        break;
      }
      cout << (fail ? "NO" : "YES") << '\n';
    }
  }
  return 0;
}