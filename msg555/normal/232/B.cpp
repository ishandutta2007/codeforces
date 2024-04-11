#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

#define MOD 1000000007

long long N, M, K;
long long ncr[128][128];
long long cmul[128][128];
long long memo[110][10010];

long long modexp(long long x, long long e) {
  long long r = 1;
  for(int i = 63 - __builtin_clzll(e); i >= 0; i--) {
    r = (r * r) % MOD;
    if(e & 1ll << i) r = (r * x) % MOD;
  }
  return r;
}

vector<long long> vmul(const vector<long long>& A, const vector<long long>& B) {
  vector<long long> R(A.size() + B.size() - 1, 0);
  for(int i = 0; i < A.size(); i++) {
    for(int j = 0; j < B.size(); j++) {
      R[i + j] = (R[i + j] + A[i] * B[j]) % MOD;
    }
  }
  return R;
}

vector<long long> vexp(const vector<long long>& A, int e) {
  vector<long long> R(1, 1);
  for(int i = 31 - __builtin_clz(e); i >= 0; i--) {
    R = vmul(R, R);
    if(e & 1 << i) R = vmul(R, A);
  }
  return R;
}

int main() {
  cin >> N >> M >> K;

  memset(memo, -1, sizeof(memo));
  for(int i = ncr[0][0] = 1; i < 128; i++) {
    for(int j = ncr[i][0] = ncr[i][i] = 1; j < i; j++) {
      ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
    }
  }
  map<long long, int> mp;
  for(int c = 0; c < N; c++) {
    ++mp[(M + N - c - 1) / N];
  }

  vector<long long> R(1, 1);
  for(typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
    vector<long long> V;
    for(int i = 0; i <= N; i++) {
      V.push_back(modexp(ncr[N][i], it->first));
    }
    R = vmul(R, vexp(V, it->second));
  }
  cout << R[K] << endl;
}