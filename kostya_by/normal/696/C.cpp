#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
const int K = 2;

struct Matrix {
  long long a[K][K];

  Matrix() {
    memset(a, 0, sizeof(a));
  }

  void identity() {
    for (int i = 0; i < K; i++) {
      a[i][i] = 1;
    }
  }

  void initialize() {
    a[0][0] = 0; a[0][1] = 1;
    a[1][0] = 2; a[1][1] = 1;
  }

  void print() {
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        cerr << a[i][j] << " ";
      }
      cerr << "\n";
    }

    cerr << "-----------------\n";
  }
};

Matrix combine(const Matrix &a, const Matrix &b) {
  Matrix c;

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
      }
    }
  }

  return c;
}

Matrix binpow(Matrix a, long long b) {
  Matrix result;
  result.identity();

  while (b) {
    if (b & 1ll) {
      result = combine(result, a);
    }

    a = combine(a, a);
    b >>= 1ll;
  }

  return result;
}

long long binpow_num(long long a, long long b) {
  long long result = 1;

  while (b) {
    if (b & 1ll) {
      result = (result * a) % MOD;
    }

    a = (a * a) % MOD;
    b >>= 1ll;
  }

  return result;
}

void solve() {
  Matrix result;
  result.initialize();
  long long q = 2;

  int n; scanf("%d", &n);
  // int n = 100000;
  for (int i = 0; i < n; i++) {
    long long a; scanf("%I64d", &a);
    // long long a = (long long) 1e18;

    result = binpow(result, a);
    q = binpow_num(q, a);
  }

  vector<long long> v = {0, 1};
  vector<long long> answer(K);

  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      answer[i] = (answer[i] + result.a[i][j] * v[j]) % MOD;
    }
  }

  long long inv_2 = (MOD + 1) / 2;

  long long p = ((answer[1] - answer[0] + MOD) * inv_2) % MOD;
  q = (q * inv_2) % MOD;

  cout << p << "/" << q << "\n";
}

int main() {
  solve();

  return 0;
}