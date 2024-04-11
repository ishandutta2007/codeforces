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

#define MAXV 100010

int A[MAXV];
int F[MAXV];

#define MOD 1000000007

int modexp(int x, int e) {
  int r = 1;
  for(int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = (1ll * r * r) % MOD;
    if(e & 1 << i) r = (1ll * r * x) % MOD;
  }
  return r;
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A[x]++;
  }
  for(int i = 100000; i >= 0; i--) {
    A[i] += A[i + 1];
  }

  memset(F, -1, sizeof(F));
  for(int i = 2; i < MAXV; i++) {
    if(F[i] != -1) continue;

    F[i] = i;
    for(int j = 2 * i; j < MAXV; j += i) {
      F[j] = i;
    }
  }

  int res = 0;
  for(int x = 1; A[x]; x++) {
    vector<int> FC(1, 1);
    for(int y = x; y > 1; ) {
      vector<int> NFC = FC;
      for(int f = F[y]; y % f == 0; ) {
        y /= f;
        for(int i = 0; i < FC.size(); i++) {
          FC[i] *= f;
          NFC.push_back(FC[i]);
        }
      }
      FC.swap(NFC);
    }
    sort(FC.begin(), FC.end());

    int val = 1;
    for(int i = 0; i + 1 < FC.size(); i++) {
      val = (1ll * val * modexp(i + 1, A[FC[i]] - A[FC[i + 1]])) % MOD;
    }
    int mu = modexp(FC.size(), A[x]) - modexp(FC.size() - 1, A[x]);
    if(mu < 0) mu += MOD;
    val = (1ll * val * mu) % MOD;
    res = (res + val) % MOD;
  }
  cout << res << endl;
  return 0;
}