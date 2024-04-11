#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#define MOD 1000000007

int C[12];
string M;

int memo[20][20][2];

int solve(int x, int num, bool on) {
  if(x == M.size()) return num == 0;
  if(num < 0) return 0;

  int& ref = memo[x][num][on];
  if(ref != -1) return ref;
  ref = 0;
  for(int i = 0; i < 10; i++) {
    if(on && i > M[x] - '0') break;
    ref += solve(x + 1, num - (i == 4 || i == 7), on && '0' + i == M[x]);
  }
  return ref;
}

int modexp(int x, int e) {
  int r = 1;
  for(int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = (1ll * r * r) % MOD;
    if(e & 1 << i) r = (1ll * r * x) % MOD;
  }
  return r;
}

int solve2(int x, int num) {
  if(x == 6) return 1;

  int ref = 0;
  for(int i = 0; i < num; i++) {
    C[i]--;
    ref = (ref + (1ll * (C[i] + 1) * solve2(x + 1, num - i)) % MOD) % MOD;
    C[i]++;
  }
  return ref;
}

int main() {
  cin >> M;
  memset(memo, -1, sizeof(memo));
  for(int i = 0; i <= M.size(); i++) {
    C[i] = solve(0, i, true);
  }
  C[0]--;

  int tot = 0;
  int res = 0;
  for(int i = 1; i <= M.size(); i++) {
    res = (res + (1ll * C[i] * solve2(0, i)) % MOD) % MOD;
/*
    tot += C[i - 1];

    long long v = C[i];
    for(int j = 0; j < 6; j++) {
      v = (v * (tot - j)) % MOD;
      //v = (v * modexp(j + 1, MOD - 2)) % MOD;
    }
    res = (res + v) % MOD;
*/
  }
  cout << res << endl;
}