#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const long long INF = 1000000000;
const double PI = 3.141592653589793;

int pr[1001000];


int getSmallest(int a) {
  if (a - pr[a] + 1 > pr[a])
    return a - pr[a] + 1;
  return INF;
}

void solve() {
  int a;
  cin >> a;
  int ans = INF;
  for (int j = 0; j < pr[a]; ++j) {
    ans = min(ans, getSmallest(a - j));
  }
  cout << ans << endl;
}

void init() {
  for (int i = 2; i < 1001000; ++i) {
    pr[i] = 0;
  }
  for (int i = 2; i < 1001000; ++i) {
    if (pr[i])
      continue;
    for (int j = 1; i * j < 1001000; ++j) {
      pr[i * j] = i;
    }
  }


}

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  return 0;
}