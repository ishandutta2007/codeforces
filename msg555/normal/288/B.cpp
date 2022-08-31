#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int N, K;

int S(int x, int msk, int act);

int NN(int msk) {
  for(int i = 0; i < K; i++) {
    if(~msk & 1 << i) {
      return S(i, msk | 1 << i, 1 << i);
    }
  }
  return K;
}

int S(int x, int msk, int act) {
  int R = 0;
  for(int i = 0; i < K; i++) {
    if(~msk & 1 << i) {
      R = (R + S(i, msk | 1 << i, act | 1 << i)) % MOD;
    } else if(~act & 1 << i) {
      R = (R + NN(msk)) % MOD;
    }
  }
  return R;
}

int main() {
  cin >> N >> K;

  int R = NN(1);
  for(int i = K; i < N; i++) {
    R = (1ll * R * (N - K)) % MOD;
  }
  cout << R << endl;

  return 0;
}