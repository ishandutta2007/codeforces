#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 510

bool cn[MAXN][MAXN];

int main() {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cn[i][i] = true;
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    cn[u - 1][v - 1] = cn[v - 1][u - 1] = true;
  }

  string S(N, 0);
  int aind = -1;
  for (int i = 0; i < N; i++) {
    bool isb = true;
    for (int j = 0; j < N; j++)  {
      isb &= cn[i][j];
    }
    if (isb) {
      S[i] = 'b';
    } else if (aind != -1 && !cn[aind][i]) {
      S[i] = 'c';
    } else {
      aind = i;  
      S[i] = 'a';
    }
  }

  bool ok = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ok &= cn[i][j] == (abs(S[i] - S[j]) <= 1);
    }
  }
  if (ok) {
    cout << "Yes" << endl;  
    cout << S << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}