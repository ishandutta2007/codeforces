#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

#define MAXV (1000000000000010LL)

int main() {
  int N, K;
  cin >> N >> K;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  map<long long, int> cnts;
  cnts[0] = 1;

  long long dst = 0;
  long long result = 0;
  for (int i = N - 1; i >= 0; i--) {
    dst += A[i];
    for (long long v = 1; v < MAXV; v *= K) {
      auto j = cnts.find(dst - v);
      if (j != cnts.end()) {
        result += j->second;
      }
      if (v == -1 && K == -1) break;
      if (K == 1) break;
    }

    cnts[dst]++;
  }
  cout << result << endl;

  return 0;
}