#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int memo[40][1 << 6][1 << 6];

int solve(int r, int ms, int mn) {
  if(r == N) return mn == 0 ? 0 : N * M;

  int& ref = memo[r][ms][mn];
  if(ref != -1) return ref;

  ref = N * M;
  for(int i = 0; i < 1 << M; i++) {
    if(mn & ~i) continue;

    int nmn = ~(i | (i >> 1) | (i << 1) | ms) & (1 << M) - 1;
    ref = min(ref, __builtin_popcount(i) + solve(r + 1, i, nmn));
  }
  return ref;
}

int main() {
  cin >> N >> M;
  if(N < M) swap(N, M);

  memset(memo, -1, sizeof(memo));
  cout << N * M - solve(0, 0, 0) << endl;
}