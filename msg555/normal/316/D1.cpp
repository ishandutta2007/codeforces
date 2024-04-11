#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1010
#define MOD 1000000007

int fact(int N) {
  int res = 1;
  for(int i = 2; i <= N; i++) {
    res = ((long long)res * i) % MOD;
  }
  return res;
}

int mmul(int x, int y) {
  return ((long long)x * y) % MOD;
}

int solve(int X, int Y) {
  if(X == 0) return fact(Y);

  int ret = 0;
  int c = 1;
  for(int i = 0; i <= Y; i++) {
    ret = (ret + mmul(c, solve(X - 1, Y - i))) % MOD;
    if(X > 1) {
      ret = (ret + mmul(mmul(X - 1, i + 1), mmul(c, solve(X - 2, Y - i)))) % MOD;
    }
    c *= Y - i;
  }
  return ret;
}

int main() {
  int N; cin >> N;
  int ones = 0;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    ones += x == 1;
  }

  cout << solve(ones, N - ones) << endl;
  return 0;
}