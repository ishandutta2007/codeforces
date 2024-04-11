#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define MOD 1000000007

long long pow2[1010];

int N;

/*
int memo[501][501][501];

int solve(int x, int y, int k) {
  if(k < 0) return 0;
  if(x == -1) return k == 0 ? 1 : 0;

  int& ref = memo[x][y][k];
  if(ref != -1) return ref;

  int na = N - y;
  int nb = y - x;
  ref = (1ll * pow2[na] * solve(x - 1, y, k)) % MOD;
  ref = (ref + 1ll * (((pow2[nb] - 1) * pow2[na]) % MOD) *
              solve(x - 1, x, k - 1)) % MOD;
  return ref;
}
*/

int DP1[510][510];
int DP2[510][510];

int getdp(int x, int y, int k) {
  if(k < 0) return 0;
  if(x == -1) return k == 0 ? 1 : 0;
  return DP2[y][k];
}

int main() {
  pow2[0] = 1;
  for(int i = 1; i < 1010; i++) {
    pow2[i] = (pow2[i - 1] * 2) % MOD;
  }

  int K;
  cin >> N >> K;

    
  for(int x = 0; x < N; x++) {
    for(int y = x + 1; y <= N; y++) {
      for(int k = 0; k <= K; k++) {
        int na = N - y;
        int nb = y - x;
        int& ref = DP1[y][k];
        ref = (1ll * pow2[na] * getdp(x - 1, y, k)) % MOD;
        ref = (ref + 1ll * (((pow2[nb] - 1) * pow2[na]) % MOD) *
                    getdp(x - 1, x, k - 1)) % MOD;
      }
    }
    memcpy(DP2, DP1, sizeof(DP1));
  }

  cout << getdp(N - 1, N, K) << endl;
  return 0;
}