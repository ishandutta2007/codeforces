#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N;
int L;
double P[100][100];
double prob[100][10];

double memo[100][10];

double solve(int A, int level) {
  double& ref = memo[A][level];
  if (ref >= 0) {
    return ref;
  }

  ref = 0;
  for (int i = A; i < A + (1 << level); i++) {
    double result = 0;
    for (int j = 1; j <= level; j++) {
      result += (1 << (j - 1)) * prob[i][j];
    }

    for (int j = 1; j < level; j++) {
      int sz = 1 << j;
      int base_x = (i ^ sz) & ~(sz - 1);
      result += solve(base_x, j);
    }
    ref = max(ref, result);
  }
  return ref;
}

int main() {
  cin >> L;
  N = 1 << L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int p; cin >> p;
      P[i][j] = p / 100.0;
    }
  }

  for (int j = 0; j <= L; j++) {
    for (int i = 0; i < N; i++) {
      memo[i][j] = -1;
      if (j == 0) {
        prob[i][j] = 1;
        continue;
      }

      int sz = 1 << (j - 1);
      int base_x = (i ^ sz) & ~(sz - 1);

      prob[i][j] = 0;
      for (int k = 0; k < sz; k++) {
        int x = base_x + k;
        prob[i][j] += prob[x][j - 1] * P[i][x];
      }
      prob[i][j] *= prob[i][j - 1];
    }
  }

  printf("%.9f\n", solve(0, L));
  return 0;
}