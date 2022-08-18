#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define MOD 1000000007

long long mexp(long long x, int e) {
  long long r = 1;
  for (int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = (r * r) % MOD;
    if (e & 1 << i) {
      r = (r * x) % MOD;
    }
  }
  return r;
}

int main() {
  long long P, K;
  cin >> P >> K;
  if (K == 0) {
    cout << mexp(P, P - 1) << endl;
  } else if (K == 1) {
    cout << mexp(P, P) << endl;
  } else {
    long long ord = 1;
    for (long long v = K; v != 1; v = (v * K) % P) {
      ord++;
    }
    cout << mexp(P, (P - 1) / ord) << endl;
  }
  return 0;
}