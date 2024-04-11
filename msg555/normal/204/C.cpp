#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

double asum[200010];
double bsum[200010];

int main() {
  int N; cin >> N;
  string A, B;
  cin >> A >> B;

  double res = 0;
  for(char ch = 'A'; ch <= 'Z'; ch++) {
    asum[N] = bsum[N] = 0;
    for(int i = N - 1; i >= 0; i--) {
      asum[i] = asum[i + 1];
      bsum[i] = bsum[i + 1];
      asum[i] += A[i] == ch ? N - i : 0;
      bsum[i] += B[i] == ch ? N - i : 0;
    }
    for(int i = 0; i < N; i++) {
      if(A[i] == ch) {
        res += (i + 1) * bsum[i];
      }
      if(B[i] == ch) {
        res += (i + 1) * asum[i];
      }
      if(A[i] == ch && B[i] == ch) {
        res -= 1ll * (i + 1) * (N - i);
      }
    }
  }

  long long sum = 0;
  for(int i = 1; i <= N; i++) {
    sum += 1ll * i * i;
  }
  printf("%.11f\n", 1.0 * res / sum);
}