#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int N, M;
int A[5010];
int C[5010];
int memo[5010][5010];

int solve(int x, int m) {
  if(x == N) return 0;

  int& ref = memo[x][m];
  if(ref != -1) return ref;

  C[A[x]]--;
  if(A[x] <= m) {
    ref = solve(x + 1, m);
  } else {
    ref = min(C[m] + solve(x, m + 1),
              1 + solve(x + 1, m));
  }
  C[A[x]]++;

  return ref;
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    double x;
    cin >> A[i] >> x;
    A[i]--;
    C[A[i]]++;
  }

  memset(memo, -1, sizeof(memo));
  cout << solve(0, 0) << endl;

  return 0;
}