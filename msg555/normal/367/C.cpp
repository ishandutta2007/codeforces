#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int N, M; cin >> N >> M;

  vector<long long> A(M);
  for(int i = 0; i < M; i++) {
    cin >> A[i] >> A[i];
  }
  sort(A.rbegin(), A.rend());

  long long res = 0;
  long long result = 0;
  for(long long r = 1; r <= A.size(); r++) {
    res += A[r - 1];

    long long mnn;
    if(r % 2 == 1) {
      mnn = r * (r - 1) / 2 + 1;
    } else {
      mnn = r * (r - 1) / 2 + (r - 2) / 2 + 1;
    }
    if(mnn <= N) {
      result = max(result, res);
    }
  }
  cout << result << endl;
  return 0;
}