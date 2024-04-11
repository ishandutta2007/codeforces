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

int P[200];
int A[200];
double DP[210][410][210];

int N, L, K;

double solve(int x, int db, int wc) {
  if(x == N) return db >= 0 && wc >= L;
  if(db > N) db = N;

  double& ref = DP[x][db + N][wc];
  if(ref != 0) return ref - 1.0;

  double p = P[x] * 1e-2;
  if(A[x] == -1) {
    ref = p * solve(x + 1, db - 1, wc + 1) +
          (1 - p) * solve(x + 1, db, wc);
  } else {
    ref = p * solve(x + 1, db + A[x], wc + 1) +
          (1 - p) * solve(x + 1, db, wc);
  }

  ref += 1.0;
  return ref - 1.0;
}

int main() {
  cin >> N >> L >> K;
  for(int i = 0; i < N; i++) cin >> P[i];
  for(int i = 0; i < N; i++) cin >> A[i];
  
  memset(DP, 0, sizeof(DP));
  printf("%.12lf\n", solve(0, K, 0));
}