#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 100010
#define MOD 1000000007

vector<int> E[MAXN];

struct ctr {
  ctr() {
    memset(A, 0, sizeof(A));
  }
  ctr operator*(const ctr& x) const {
    ctr nv;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          nv.A[i][j] = (nv.A[i][j] + 1LL * A[i][k] * x.A[k][j]) % MOD;
        }
      }
    }
    return nv;
  }
  ctr operator+(const ctr& x) const {
    ctr nv;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        nv.A[i][j] = (A[i][j] + x.A[i][j]) % MOD;
      }
    }
    return nv;
  }
  void print() {
    cout << A[0][0] << ' ' << A[0][1] << endl;
    cout << A[1][0] << ' ' << A[1][1] << endl;
  }
  int A[2][2];
};

ctr memo[MAXN];

ctr solve(int x) {
  if (memo[x].A[0][0] != -1) {
    return memo[x];
  }

  ctr r1, r2;
  r1.A[0][1] = r2.A[0][1] = 1;
  r1.A[1][0] = r2.A[1][0] = 1;

  for(int i = 0; i < E[x].size(); i++) {
    r1 = r1 + r1 * solve(E[x][i]);
  }
  for(int i = E[x].size() - 1; i >= 0; i--) {
    r2 = r2 + r2 * solve(E[x][i]);
  }
  r1 = r1 + r2;

  /* Discount all even, odd number of odd. */
  int ev = 1;
  int odd[2] = {1, 0};
  for(int i = 0; i < E[x].size(); i++) {
    ctr res = solve(E[x][i]);
    ev = (ev + 1ll * ev * res.A[0][0]) % MOD;

    int o0 = odd[0];
    int o1 = odd[1];
    odd[0] = (o0 + 1ll * o1 * res.A[0][1]) % MOD;
    odd[1] = (o1 + 1ll * o0 * res.A[0][1]) % MOD;
  }
  r1.A[0][1] = (r1.A[0][1] - ev + MOD) % MOD;
  r1.A[1][0] = (r1.A[1][0] - ev + MOD) % MOD;
  r1.A[0][0] = (r1.A[0][0] - odd[1] + MOD) % MOD;
  r1.A[1][1] = (r1.A[1][1] - odd[1] + MOD) % MOD;

  memo[x] = r1;
  return r1;
}

int main() {
  int N;
  cin >> N;
  for(int i = 1; i < N; i++) {
    int p;
    cin >> p;
    E[p - 1].push_back(i);
  }

  memset(memo, -1, sizeof(memo));
  ctr result = solve(0);
  cout << (result.A[0][0] + result.A[0][1]) % MOD << endl;
  return 0;
}