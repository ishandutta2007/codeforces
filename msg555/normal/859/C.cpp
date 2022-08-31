#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define MAXN 100

int A[MAXN];
int SM[MAXN];
int DP[MAXN];

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = N - 1; i >= 0; i--) {
    SM[i] = A[i] + SM[i + 1];
    DP[i] = max(DP[i + 1], A[i] + (SM[i + 1] - DP[i + 1]));
  }

  cout << SM[0] - DP[0] << ' ' << DP[0] << '\n';

  return 0;
}