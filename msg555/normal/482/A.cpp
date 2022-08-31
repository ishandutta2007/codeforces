#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int L = 1;
  bool high = false;

  cout << L;
  for (int i = 1; i < N; i++) {
    if (K == 1) {
      if (high) {
        L--;
      } else {
        L++;
      }
    } else {
      if (high) {
        L = N - L + 2;
      } else {
        L = N - L + 1;
      }
      high = !high;

      K--;
    }
    cout << ' ' << L;
  }
  cout << '\n';

  return 0;
}