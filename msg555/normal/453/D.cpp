#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAXM 22

int M, P;
long long T;

int A[MAXM][MAXM];
int R[MAXM][MAXM];
int TMP[MAXM][MAXM];

int ncr[MAXM][MAXM];

int X[1 << 20];
int B[MAXM];

int mmul(int x, int y) {
  return (1ll * x * y) % P;
}

void madd(int& x, int y) {
  x += y;
  if(x >= P) x -= P;
}

void matmul(int X[MAXM][MAXM], int Y[MAXM][MAXM], int Z[MAXM][MAXM]) {
  for(int i = 0; i <= M; i++) {
    for(int j = 0; j <= M; j++) {
      X[i][j] = 0;
      for(int k = 0; k <= M; k++) {
        madd(X[i][j],  mmul(Y[i][k], Z[k][j]));
      }
    }
  }
}

void solve(int x, int pos, vector<int>& V) {
  if(pos == 0) {
    X[x] = 0;
    for(int i = 0; i <= M; i++) {
      madd(X[x], mmul(B[i], V[i]));
    }
    return;
  }

  pos--;
  int sz = M - pos;

  int flp = 1 << pos;
  for(int i = 0; i < 2 * flp; i += flp) {
    vector<int> NV((sz + 1) * flp);

    for(int j = 0; j < sz; j++) {
      for(int k = 0; k < flp; k++) {
        madd(NV[j * flp + k], V[j * (flp * 2) + i + k]);
        madd(NV[(j + 1) * flp + k], V[j * (flp * 2) + (flp - i) + k]);
      }
    }

    solve(x | i, pos, NV);
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> M >> T >> P;
  for(int i = 0; i < 1 << M; i++) {
    cin >> X[i];
    //X[i] = rand() % P;
    //X[i] = 1;

    X[i] %= P;
  }
  for(int i = 0; i <= M; i++) {
    cin >> B[i];
    //B[i] = rand() % P;
    //B[i] = 1;

    B[i] %= P;
  }

  for(int i = ncr[0][0] = 1; i < MAXM; i++) {
    for(int j = ncr[i][0] = ncr[i][i] = 1; j < i; j++) {
      ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % P;
    }
  }

  for(int i = 0; i <= M; i++) {
    for(int j = 0; j <= M; j++) {
      R[i][j] = i == j ? 1 : 0;
      for(int k = 0; k <= i && k <= j; k++) {
        int v = mmul(ncr[i][k], ncr[M - i][j - k]);
        v = mmul(v, B[i + j - 2 * k]);
        A[i][j] = (A[i][j] + v) % P;
      }
    }
  }

  for(int i = 63 - __builtin_clzll(T); i >= 0; i--) {
    matmul(TMP, R, R);
    memcpy(R, TMP, sizeof(R));

    if(T & 1LL << i) {
      matmul(TMP, R, A);
      memcpy(R, TMP, sizeof(R));
    }
  }

/*
  for(int i = 0; i <= M; i++) {
    for(int j = 0; j <= M; j++) {
      cout << R[i][j] << ' ';
    }
    cout << endl;
  }
*/

  for(int i = 0; i <= M; i++) {
    B[i] = R[i][0];
  }

/*
  for(int i = 0; i < 1 << M; i++) {
    int sm = 0;
    for(int j = 0; j < 1 << M; j++) {
      sm = (sm + mmul(X[j], B[__builtin_popcount(i ^ j)])) % P;
    }
    cout << sm << '\n';
  }
*/

  vector<int> V(X, X + (1 << M));
  solve(0, M, V);

  for(int i = 0; i < 1 << M; i++) {
    cout << X[i] << '\n';
  }

  return 0;
}