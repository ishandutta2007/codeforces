#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

int N, M;
bool bad[35][35];

pair<int, int> A[35][35];
pair<int, int> B[35][35];

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

vector<pair<int, int> > R;

void domove(int r, int c) {
  int mr = B[0][0].first;
  int mc = B[0][0].second;
  swap(B[0][0], B[A[r][c].first][A[r][c].second]);
  swap(A[mr][mc], A[r][c]);
  R.push_back(make_pair(r, c));
}

void path(int tr, int tc, int xr, int xc) {
  bad[xr][xc] = true;

  queue<int> q;
  q.push(tr * M + tc);
  vector<int> dd(M * N, -1);
  dd[tr * M + tc] = 0;
  while(!q.empty()) {
    int u = q.front();
    int ur = u / M;
    int uc = u % M;
    q.pop();
    for(int i = 0; i < 8; i++) {
      int vr = ur + dr[i];
      int vc = uc + dc[i];
      int v = vr * M + vc;
      if (vr < 0 || vr >= N || vc < 0 || vc >= M || bad[vr][vc]) continue;
      if (dd[v] == -1) {
        dd[v] = dd[u] + 1;
        q.push(v);
      }
    }
  }

  int& mr = B[0][0].first;
  int& mc = B[0][0].second;
  while(mr != tr || mc != tc) {
    int m = mr * M + mc;
    for(int i = 0; i < 8; i++) {
      int vr = mr + dr[i];
      int vc = mc + dc[i];
      int v = vr * M + vc;
      if (vr < 0 || vr >= N || vc < 0 || vc >= M || bad[vr][vc]) continue;
      if(dd[v] + 1 == dd[m]) {
        domove(vr, vc);
        break;
      }
    }
  }

  bad[xr][xc] = false;
}

void move(int tr, int tc) {
  int& pr = B[tr][tc].first;
  int& pc = B[tr][tc].second;
  while(pr > tr) {
    path(pr - 1, pc, pr, pc);
    domove(pr, pc);
  }
  while(pc > tc) {
    path(pr, pc - 1, pr, pc);
    domove(pr, pc);
  }
  while(pr < tr) {
    path(pr + 1, pc, pr, pc);
    domove(pr, pc);
  }
  while(pc < tc) {
    path(pr, pc + 1, pr, pc);
    domove(pr, pc);
  }
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[i][j].first;
      //A[i][j].first = i * M + j;
    }
  }
  map<int, vector<pair<int, int> > > mp;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> B[i][j].first;
      //B[i][j].first = j * N + i;
      mp[B[i][j].first].push_back(make_pair(i, j));
    }
  }

  if (N == 1 || M == 1) {
    vector<int> V1, V2;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        V1.push_back(A[i][j].first);
        V2.push_back(B[i][j].first);
      }
    }
    if (V1 == V2) {
      cout << "0\n1 1\n";
      return 0;
    }
    for(int i = 0; i + 1 < V1.size(); i++) {
      vector<int> NV = V1;
      for(int j = i + 1; j < V1.size(); j++) {
        swap(NV[j - 1], NV[j]);
        if (NV == V2) {
          cout << j - i << "\n";
          for(int k = i; k <= j; k++) {
            if(N == 1) {
              cout << 1 << " " << k + 1 << "\n";
            } else {
              cout << k + 1 << " 1\n";
            }
          }
          return 0;
        }
      }
      NV = V1;
      for(int j = i - 1; j >= 0; j--) {
        swap(NV[j + 1], NV[j]);
        if (NV == V2) {
          cout << i - j << "\n";
          for(int k = i; k >= j; k--) {
            if(N == 1) {
              cout << 1 << " " << k + 1 << "\n";
            } else {
              cout << k + 1 << " 1\n";
            }
          }
          return 0;
        }
      }
    }
    cout << "-1\n";
    return 0;
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      vector<pair<int, int> >& V = mp[A[i][j].first];
      if (V.empty()) {
        cout << "-1\n";
        return 0;
      }
      A[i][j] = V.back();
      B[A[i][j].first][A[i][j].second] = make_pair(i, j);
      V.resize(V.size() - 1);
    }
  }

  R.push_back(B[0][0]);
  while(N && M) {
    if (N > M) {
      for(int i = M - 1; i >= 0; i--) {
        move(N - 1, i);
        bad[N - 1][i] = true;
      }
      N--;
    } else {
      for(int i = N - 1; i >= 0; i--) {
        move(i, M - 1);
        bad[i][M - 1] = true;
      }
      M--;
    }
  }

  cout << R.size() - 1 << "\n";
  for(int i = 0; i < R.size(); i++) {
    cout << R[i].first + 1 << ' ' << R[i].second + 1 << "\n";
  }

  return 0;
}