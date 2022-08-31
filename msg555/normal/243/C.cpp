#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

#define FSZ 2010
bool A[FSZ][FSZ];
bool VIS[FSZ][FSZ];

int main() {
  int N; cin >> N;
  vector<int> xs, ys;

  int x = 0, y = 0;
  vector<pair<pair<int, int>, int> > V;
  for(int i = 0; ; i++) {
    xs.push_back(x); xs.push_back(x + 1);
    ys.push_back(y); ys.push_back(y + 1);
    if(i == N) break;

    string sdir; cin >> sdir;
    int amt; cin >> amt;
    int dir = -1;
    if(sdir == "R") dir = 0;
    if(sdir == "L") dir = 1;
    if(sdir == "D") dir = 2;
    if(sdir == "U") dir = 3;
    V.push_back(make_pair(make_pair(x, y), dir));
    x += amt * dx[dir];
    y += amt * dy[dir];
  }
  V.push_back(make_pair(make_pair(x, y), -1));

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
  for(int i = 0; i < V.size(); i++) {
    V[i].first.first =
        lower_bound(xs.begin(), xs.end(), V[i].first.first) - xs.begin() + 1;
    V[i].first.second =
        lower_bound(ys.begin(), ys.end(), V[i].first.second) - ys.begin() + 1;
  }

  int XN = xs.size() - 1;
  int YN = ys.size() - 1;
  memset(A, 0, sizeof(A));
  for(int i = 0; i + 1 < V.size(); i++) {
    int x = V[i].first.first;
    int y = V[i].first.second;
    int dir = V[i].second;
    while(1) {
      A[x][y] = true;
      if(x == V[i + 1].first.first && y == V[i + 1].first.second) break;
      x += dx[dir];
      y += dy[dir];
    }
  }

  queue<int> q;
  memset(VIS, 0, sizeof(VIS));
  q.push(0);
  VIS[0][0] = true;
  while(!q.empty()) {
    int vr = q.front() / FSZ;
    int vc = q.front() % FSZ;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nr = vr + dx[i];
      int nc = vc + dy[i];
      if(nr < 0 || nr >= FSZ || nc < 0 || nc >= FSZ ||
         VIS[nr][nc] || A[nr][nc]) continue;
      VIS[nr][nc] = true;
      q.push(nr * FSZ + nc);
    }
  }

  long long res = 0;
  for(int i = 0; i < XN; i++) {
    for(int j = 0; j < YN; j++) {
      if(!VIS[1 + i][1 + j]) {
        res += 1ll * (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);
      }
    }
  }
  cout << res << endl;
  return 0;
}