#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int lo = 1;
  int hi = 10000000;
  while (lo < hi) {
    int md = (lo + hi) / 2;

    int n6 = md / 6;
    int n2 = md / 2 - n6;
    int n3 = md / 3 - n6;

    if (N > n2) {
      n6 -= N - n2;
    }
    if (0 <= n6 && M <= n3 + n6) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  cout << lo << endl;

  return 0;
}