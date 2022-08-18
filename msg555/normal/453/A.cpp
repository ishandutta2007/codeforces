#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int M, N;
  cin >> M >> N;

  double p = 0;
  double res = 0;
  for(int i = 1; i <= M; i++) {
    double np = pow(1.0 * i / M, N);
    res += i * (np - p);
    p = np;
  }
  printf("%.12f\n", res);
}