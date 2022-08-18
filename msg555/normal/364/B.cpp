#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

bool A[600010];
int X[50];

int main() {
  int N, D; cin >> N >> D;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
  }

  int sm = 0;
  A[0] = true;
  for(int i = 0; i < N; i++) {
    sm += X[i];
    for(int j = sm; j >= X[i]; j--) {
      A[j] |= A[j - X[i]];
    }
  }

  int cnt = 0;
  int result = 0;
  for(;; cnt++) {
    int i;
    for(i = D; i; i--) {
      if(A[result + i]) {
        result += i;
        break;
      }
    }
    if(!i) break;
  }

  cout << result << ' ' << cnt << endl;
  return 0;
}