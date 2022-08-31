#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int cnt1 = 1 + (A[0] == A[2] ? 1 : 0) + (A[1] == A[2] ? 1 : 0);
  int cnt2 = cnt1;
  for (int i = 3; i < N; i++) {
    if (A[i] == A[2]) {
      cnt2++;
    }
  }

  long long r = 1;
  for (int i = 0; i < cnt1; i++) {
    r *= cnt2 - i;
    r /= i + 1;
  }
  cout << r << endl;
  
  return 0;
}