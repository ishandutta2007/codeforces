#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int N, M;
long long memo[1 << 16];

int B[16];
vector<int> E[16];
vector<int> E2[16];

int LO[16];
int HI[16];
int SS[16];

bool can(int x, int v) {
  bool ok = true;
  for(int j = 0; ok && j < E[x].size(); j++) {
    int vb = B[E[x][j]];
    if(vb != -1) ok = v < vb;
  }
  for(int j = 0; ok && j < E2[x].size(); j++) {
    int vb = B[E2[x][j]];
    if(vb != -1) ok = vb < v;
  }
  return ok;
}

void build() {
  for(int i = 0; i < N; i++) {
    SS[i] = 0;
    for(int j = 0; j < E2[i].size(); j++) {
      SS[i] |= 1 << E2[i][j];
    }
    LO[i] = -1; HI[i] = N;
  }
  for(int i = 0; i < N; i++) {
    if(B[i] == -1) continue;
    for(int j = 0; j < E[i].size(); j++) {
      int v = E[i][j];
      LO[v] = max(LO[v], B[i]);
    }
    for(int j = 0; j < E2[i].size(); j++) {
      int v = E2[i][j];
      HI[v] = min(HI[v], B[i]);
    }
  }
}

long long solve(int m1, int m2) {
  if(m1 == (1 << N) - 1) return 1;
  long long& ref = memo[m1];
  if(ref != -1) return ref;

  ref = 0;
  int x = __builtin_ctz(~m2);
  for(int i = 0; i < N; i++) {
    if(m1 & 1 << i) continue;
    if(x < LO[i] || HI[i] < x) continue;
    if(SS[i] & ~m1) continue;

    ref += solve(m1 | 1 << i, m2 | 1 << x);
  }
  return ref;
}

int main() {
  long long Y;
  cin >> N >> Y >> M; Y -= 2001;

  memset(B, -1, sizeof(B));
  memset(memo, -1, sizeof(memo));

  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b; a--; b--;
    E[a].push_back(b);
    E2[b].push_back(a);
  }

  build();
  if(Y >= solve(0, 0)) {
    cout << "The times have changed" << endl;
  } else {
    int m1 = 0;
    int m2 = 0;
    for(int i = 0; i < N; i++) {
      m1 |= 1 << i;
      for(B[i] = 0; B[i] < N; B[i]++) {
        if(m2 & 1 << B[i]) continue;
        if(!can(i, B[i])) continue;

        memset(memo, -1, sizeof(memo));
        build();
        long long res = solve(m1, m2 | 1 << B[i]);

        if(Y >= res) {
          Y -= res;
        } else {
          if(i) cout << ' ';
          cout << B[i] + 1;
          m2 |= 1 << B[i];
          break;
        }
      }
    }
    cout << endl;
  }
}