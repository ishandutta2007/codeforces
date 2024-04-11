#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <stdint.h>

using namespace std;

#define MAXN 155

typedef uint32_t u32;

int N, M;
u32 A[32][MAXN][MAXN/32+1];

void setb(u32* X, int x) {
  X[x >> 5] |= u32(1) << (x & 0x1F);
}

bool getb(u32* X, int x) {
  return X[x >> 5] & u32(1) << (x & 0x1F);
}

void mul(u32 R[MAXN][MAXN/32+1], u32 X[MAXN][MAXN/32+1],
                                 u32 Y[MAXN][MAXN/32+1]) {
  memset(R, 0, sizeof(R));
  for (int j = 0; j < N; j++) {
    u32 yi[MAXN/32+1] = {0};
    for (int k = 0; k < N; k++) {
      if (getb(Y[k], j)) {
        setb(yi, k);
      }
    }
    for (int i = 0; i < N; i++) {
      for (int k = 0; (k << 5) < N; k++) {
        if (X[i][k] & yi[k]) {
          setb(R[i], j);
          break;
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;

  vector<pair<int, pair<int, int> > > F(M);
  for (int i = 0; i < M; i++) {
    cin >> F[i].second.first >> F[i].second.second >> F[i].first;
    F[i].second.first--;
    F[i].second.second--;
  }
  sort(F.begin(), F.end());
  F.push_back(make_pair(1000010000, make_pair(0, 0)));

  if (F[0].first != 0) {
    cout << "Impossible\n";
    return 0;
  }

  int tm = 0;
  u32 V[MAXN/32+1] = {0};
  setb(V, 0);

  bool found = false;
  for (int i = 1; i < F.size() && !found; i++) {
    int dt = F[i].first - F[i - 1].first;
    if (dt == 0) continue;

    memset(A, 0, sizeof(A));
    setb(A[0][N - 1], N - 1);
    for (int j = 0; j < i; j++) {
      setb(A[0][F[j].second.first], F[j].second.second);
    }

    int cnt = 32 - __builtin_clz(dt);
    for (int j = 1; j < cnt; j++) {
      mul(A[j], A[j - 1], A[j - 1]);
    }

    for (int j = cnt - 1; j >= 0; j--) {
      if (~dt & 1 << j) {
        continue;
      }

      u32 NV[MAXN/32+1] = {0};
      for (int k = 0; k < N; k++) {
        if (getb(V, k)) {
          for (int a = 0; (a << 5) < N; a++) {
            NV[a] |= A[j][k][a];
          }
        }
      }
      if (!getb(NV, N - 1)) {
        tm += 1 << j;
        memcpy(V, NV, sizeof(V));
      } else {
        dt = (1 << j) - 1;
        found = true;
      }
    }
  }

  if (!found) {
    cout << "Impossible\n";
  } else {
    cout << tm + 1 << endl;
  }
}