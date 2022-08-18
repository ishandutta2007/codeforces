#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#include <cstdlib>

using namespace std;

int N, K, H;
pair<int, pair<int, int> > A[100000];
int B[100000];

bool test(double T) {
  int p = K;
  for(int i = N - 1; i >= 0 && p > 0; i--) {
    if(1.0 * p * H / A[i].second.first < T) {
      B[--p] = A[i].second.second;
    }
  }
  return p == 0;
}

int main() {
  cin >> N >> K >> H;
  for(int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second.second = i;
  }
  for(int i = 0; i < N; i++) {
    cin >> A[i].second.first;
  }

  sort(A, A + N);

  double lo = 0;
  double hi = K * H + 1;
  for(int ii = 0; ii < 100; ii++) {
    double md = (lo + hi) / 2;
    if(test(md)) {
      hi = md;
    } else {
      lo = md;
    }
  }

  test(hi);
  for(int i = 0; i < K; i++) {
    if(i) cout << ' ';
    cout << B[i] + 1;
  }
  cout << endl;
}