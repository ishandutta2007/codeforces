#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1010

double prob(int T, int M, int D, int w) {
  if(w < 0) return 0;
  if(D == 0) return w == 0 ? 1 : 0;
  
  double p = 1.0 * M / T;
  return p * prob(T - 1, M - 1, D - 1, w - 1) +
         (1 - p) * prob(T - 1, M, D - 1, w);
}

double ncr(int n, int r) {
  double res = 1;
  for(int i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

double P[MAXN];

int main() {
  int N, M; cin >> N >> M;

  double norm = 0;
  for(int i = 0; i <= N; i++) {
    //P[i] = prob(N * M, M, N, i);
    P[i] = ncr(M, i) * ncr((N - 1) * M, N - i) / ncr(N * M, N);
  //P[i] = (M choose i) * ((N - 1) * M choose N - i) / (N * M choose N)
//cout << i << ": " << P[i] << endl;
    norm += i * P[i];
  }


  double res = 0;
  for(int i = 1; i <= N; i++) {
    double p = P[i] * i / norm;
    res += p * i / N;
  }
  printf("%.9f\n", res);
  
  return 0;
}