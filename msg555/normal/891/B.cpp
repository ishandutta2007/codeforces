#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<long long> B = A;
  sort(B.begin(), B.end());
  for (int i = 0; i < N; i++) {
    int ind = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
    if (i) cout << ' ';
    cout << B[ind % N];
  }
  cout << '\n';

  return 0;
}