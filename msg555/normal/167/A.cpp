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
#include <cmath>
#include <numeric>

using namespace std;

int main() {
  double lt = 0;
  int N, A, D; cin >> N >> A >> D;
  for(int i = 0; i < N; i++) {
    int T, V; cin >> T >> V;

    double dt;
    double dta = 1.0 * V / A;
    if(0.5 * A * dta * dta > D) {
      dt = sqrt(2.0 * D / A);
    } else {
      dt = dta + (D - 0.5 * A * dta * dta) / V;
    }
    lt = max(T + dt, lt);

    printf("%.12lf\n", lt);
  }
  return 0;
}