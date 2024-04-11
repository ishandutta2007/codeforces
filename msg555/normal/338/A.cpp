#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MOD 1000000009

int modexp(int x, int e) {
  int r = 1;
  for(int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = ((long long)r * r) % MOD;
    if(e & 1 << i) {
      r = ((long long)r * x) % MOD;
    }
  }
  return r;
}

int main() {
  long long N, M, K;
  cin >> N >> M >> K;

  long long V = N - M;
  if((V + 1) * K - 1 >= N) {
    cout << M << endl;
  } else {
    long long result = V * (K - 1);
    M -= result;


    result += K * (modexp(2, M / K + 1) + MOD - 2);
    result += M % K;
    cout << result % MOD << endl;
  }

  return 0;
}