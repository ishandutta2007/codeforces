#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

long long A[100010];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A, A + N);
  long long result = 0;
  for(int i = 0; i < N; i++) {
    long long amt = A[N - 1] - max(result, A[i]);
    result += amt;
  }

  result += ((A[N - 1] - result) * N + N - 2) / (N - 1);
  cout << result << endl;

  return 0;
}