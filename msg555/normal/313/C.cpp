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
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int w = 1;
  int m = 1;
  for(int x = N; x > 1; x /= 4) w++;

  long long res = 0;
  sort(A.rbegin(), A.rend());
  for(int i = 0; i < A.size(); i++) {
    if(i == m) {
      m *= 4;
      w--;
    }
    res += (long long)w * A[i];
  }

  cout << res << endl;
  return 0;
}