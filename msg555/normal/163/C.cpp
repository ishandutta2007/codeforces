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

long long A[300000];
double R[100010];

int main() {
  long long N, L, v1, v2;
  cin >> N >> L >> v1 >> v2;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  for(int i = 0; i < N; i++) {
    A[i + N] = A[i] + 2 * L;
    A[i + 2*N] = A[i] + 4 * L;
  }
  double dl = 1.0 * v2 * L / (v1 + v2);

  int ii = 0;
  int jj = 0;
  double xp = A[0];
  for(; A[jj + 1] < xp + dl; jj++);

  while(xp < A[N]) {
    int amt = jj - ii;
    double nxp = A[ii + 1] < A[jj + 1] - dl ? A[++ii] : A[++jj] - dl;
    R[amt] += nxp - xp;
    xp = nxp;
  }

  for(int i = 0; i <= N; i++) {
    R[i] /= 2 * L;
  }
  for(int i = 0; i <= N; i++) printf("%.12f\n", R[i]);
  return 0;
}