#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

int A[2020];

int main() {
  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  int result = 0;
  for(int i = 0; i < N; i++) {
    if (i % K == 0) {
      result += 2 * A[N - i - 1] - 2;
    }
  }
  cout << result << endl;

  return 0;
}