#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int R, C;
string A[1010];
int D[1010][1010];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
  cin >> R >> C;
  for(int i = 0; i < R; i++) {
    cin >> A[i];
  }

  int tr = -1;
  int tc = -1;

  queue<int> q;
  memset(D, -1, sizeof(D));
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(A[i][j] == 'E') {
        D[i][j] = 0;
        q.push(i * C + j);
      } else if(A[i][j] == 'S') {
        tr = i;
        tc = j;
      }
    }
  }

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    int ur = u / C;
    int uc = u % C;

    for(int i = 0; i < 4; i++) {
      int nr = ur + dr[i];
      int nc = uc + dc[i];
      if(nr < 0 || nr >= R || nc < 0 || nc >= C ||
         A[nr][nc] == 'T' ||D[nr][nc] != -1) {
        continue;
      }

      D[nr][nc] = D[ur][uc] + 1;
      q.push(nr * C + nc);
    }
  }

  int result = 0;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(D[i][j] != -1 && D[i][j] <= D[tr][tc] &&
         '0' < A[i][j] && A[i][j] <= '9') {
        result += A[i][j] - '0';
      }
    }
  }
  cout << result << endl;
  return 0;
}