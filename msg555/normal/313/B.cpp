#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <complex>

using namespace std;

int main() {
  string S; cin >> S;

  int N = S.size();
  vector<int> A(1, 0);
  for(int i = 0; i + 1 < N; i++) {
    A.push_back(A[i] + (S[i] == S[i + 1] ? 1 : 0));
  }
  A.push_back(A.back());
  int Q; cin >> Q;
  for(int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << A[b] - A[a] << "\n";
  }
  return 0;
}