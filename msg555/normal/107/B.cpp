#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int A[1000];

long double ncr(int n, int r) {
  if(r > n) return 0;
  if(r < 0) return 0;

  long double ret = 1;
  for(int i = 1; i <= r; i++) {
    ret *= n - i + 1;
    ret /= i;
  }
  return ret;
}

int main() {
  int N, M, H;
  cin >> N >> M >> H;

  int sum = 0;
  for(int i = 0; i < M; i++) {
    cin >> A[i];
    sum += A[i];
  }
  if(sum < N) {
    cout << -1 << endl;
    return 0;
  }

  --N; --sum;
  int amt = A[H - 1] - 1;

  long double ret = 0;
  for(int i = 1; i <= amt; i++) {
    int bamt = N - i;
    int bsum = sum - amt;

    ret += ncr(bsum, bamt) * ncr(amt, i);
  }

  printf("%.9f\n", (double)(ret / ncr(sum, N)));
}