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

#define MAXN 60

int N;
int M;

string A[MAXN];

int toind(char ch) {
  if('a' <= ch && ch <= 'z') {
    return ch - 'a';
  } else {
    return (ch - 'A') + 26;
  }
}

long long MASKS[20][60];

int KN[1 << 20];
double memo[1 << 20];

double solve(int m, const vector<long long>& msklst, int lsti) {
  double& ref = memo[m];
  if(ref == ref) return ref;

  vector<long long> msk = msklst;
  if (lsti != -1) {
    for(int i = 0; i < N; i++) {
      msk[i] &= MASKS[lsti][i];
    }
  }
  KN[m] = 0;
  for(int i = 0; i < N; i++) {
    if(msk[i] == 1LL << i) {
      KN[m]++;
    }
  }
  if(KN[m] == N) {
    return 0;
  }

  ref = 0;
  int ntries = 0;
  int ctotal = N - KN[m];
  for(int i = 0; i < M; i++) {
    if (m & 1 << i) {
      continue;
    }

    int nm = m | 1 << i;
    double res = solve(nm, msk, i);
    int cknown = KN[nm] - KN[m];
    double p = 1.0 * cknown / ctotal;
    if (cknown == ctotal) {
      res = 1;
    } else {
      res = p + (1 - p) * (1 + res);
    }
    ref += res;
    ntries++;
  }
  ref /= ntries;
  return ref;
}

int main() {
  cin >> N;
//N = 50;

  for(int i = 0; i < N; i++) {
    cin >> A[i];

/*
A[i] = string(20, 'a');
A[i][0] = i < 25 ? 'a' + i : 'A' + (i - 25);
cout << A[i] << endl;
*/
  }
  M = A[0].size();

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < 52; j++) {
      long long m = 0;
      for(int k = 0; k < N; k++) {
        if (toind(A[k][i]) == j) {
          m |= 1LL << k;
        }
      }
      for(int k = 0; k < N; k++) {
        if (toind(A[k][i]) == j) {
          MASKS[i][k] = m;
        }
      }
    }
  }

  vector<long long> V(N, (1LL << N) - 1);
  memset(memo, -1, sizeof(memo));
  printf("%.9lf\n", solve(0, V, -1));

  return 0;
}