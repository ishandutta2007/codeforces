#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

int G[16][110];

bool B[110][2];

int main() {
  memset(G, -1, sizeof(G));

  for(int i = 0; i < 16; i++) {
    G[i][0] = 0;
  }
  for(int j = 1; j <= 105; j++) {
    for(int i = 0; i < 16; i++) {
      if((i & 5) == 5 || (i & 10) == 10) {
        continue;
      }

      vector<int> gs;
      for(int k = (i & 4 ? 1 : 0); k + (i & 8 ? 1 : 0) < j; k++) {
        gs.push_back(G[(i & 5) | 2][max(0, k)] ^
                     G[(i & 10) | 1][max(0, j - k - 1)]);
      }
      for(int k = (i & 1 ? 1 : 0); k + (i & 2 ? 1 : 0) < j; k++) {
        gs.push_back(G[(i & 5) | 8][max(0, k)] ^
                     G[(i & 10) | 4][max(0, j - k - 1)]);
      }
      sort(gs.begin(), gs.end());
      gs.resize(unique(gs.begin(), gs.end()) - gs.begin());

      G[i][j] = 0;
      assert(gs.empty() || gs[0] >= 0);
      for(int& g = G[i][j]; g < gs.size() && gs[g] == g; g++);
    }
  }

  int R, N;
  cin >> R >> N;
  for(int i = 0; i < N; i++) {
    int r, c; cin >> r >> c;
    r--; c--;
    B[r][c] = true;
    B[r][1 - c] = true;
    if(r > 0) B[r - 1][1 - c] = true;
    if(r + 1 < R) B[r + 1][1 - c] = true;
  }

  int gg = 0;
  for(int i = 0; ; ) {
    while(i < R && B[i][0] && B[i][1]) i++;
    if(i == R) break;

    int sz = 0;
    int lf = 0;
    int rh = 0;
    while(i + sz < R && !(B[i + sz][0] && B[i + sz][1])) {
      if(B[i + sz][0]) {
        lf++;
      } else if(B[i + sz][1]) {
        rh++;
      }
      sz++;
    }

    if(lf == 0 && rh == 0) {
      gg ^= G[0][sz];
    } else if(lf + rh == 1) {
      gg ^= G[1][sz];
    } else if(lf == 2 || rh == 2) {
      gg ^= G[3][sz];
    } else if(lf == 1 && rh == 1) {
      gg ^= G[9][sz];
    } else {
      assert(0);
    }

    i += sz;
  }

  if(gg) {
    cout << "WIN" << endl;
  } else {
    cout << "LOSE" << endl;
  }

  return 0;
}