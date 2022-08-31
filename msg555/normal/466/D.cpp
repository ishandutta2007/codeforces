#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

#define MAXN 2010
#define MOD 1000000007

int N, H;
int A[MAXN];
int memo[MAXN][MAXN];

int mmul(int x, int y) {
  return (1ll * x * y) % MOD;
}

int madd(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int solve(int x, int c) {
  if(x == N) {
    return c <= 1 ? 1 : 0;
  }

  int& ref = memo[x][c];
  if(ref != -1) return ref;
  ref = 0;

  int av = A[x] + c;
  if (av == H) {
    /* start/stop or move through */
    ref = madd(ref, mmul(c + 1, solve(x + 1, c)));
  }
  if (av + 1 == H) {
    /* Start here */
    ref = madd(ref, solve(x + 1, c + 1));
  }
  if (av - 1 == H && c > 0) {
    /* Stop here */
    ref = madd(ref, mmul(c, solve(x + 1, c - 1)));
  }
  
  return ref;
}

int main() {
  cin >> N >> H;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  memset(memo, -1, sizeof(memo));
  cout << solve(0, 0) << endl;
  return 0;
}