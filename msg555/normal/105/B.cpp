#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

double pmul[1 << 8];

int N;
int B[8];
int P[8];

double solve(int x, int k) {
  if(x == N) {
    double result = 0;
    for(int i = 0; i < 1 << N; i++) {
      double p = 1;
      for(int j = 0; j < N; j++) {
        if(i & 1 << j) {
          p *= P[j] * 1e-2;
        } else {
          p *= (100 - P[j]) * 1e-2;
        }
      }
      result += p * pmul[i];
    }
    return result;
  }
  int orig = P[x];
  double ret = 0;
  for(int i = 0; P[x] <= 100 && i <= k; i++, P[x] += 10) {
    ret = max(ret, solve(x + 1, k - i));
  }
  P[x] = orig;
  return ret;
}

int main() {
  int K, A; cin >> N >> K >> A;
  for(int i = 0; i < N; i++) {
    cin >> B[i] >> P[i];
  }
  for(int i = 0; i < 1 << N; i++) {
    if(__builtin_popcount(i) * 2 > N) {
      pmul[i] = 1;
    } else {
      int sumb = 0;
      for(int j = 0; j < N; j++) {
        if(!(i & 1 << j)) sumb += B[j];
      }
      pmul[i] = 1.0 * A / (A + sumb);
    }
  }
  printf("%.9f\n", solve(0, K));
}