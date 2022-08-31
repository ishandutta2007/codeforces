#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int P[100010];
int A[100010];
int B[100010];
int OA[100010];
int OB[100010];
  
int find(int x) {
  return x == P[x] ? x : P[x] = find(P[x]);
}

int merge(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if(X == Y) return X;

  int G = rand() & 1 ? X : Y;
  P[x] = P[y] = P[X] = P[Y] = G;

  A[G] = min(A[X], A[Y]);
  B[G] = max(B[X], B[Y]);
  return G;
}

set<int> itvs[1 << 19];

void insert(int x, int A, int B, int a, int b, int v) {
  if(b <= A || B <= a) return;
  if(a <= A && B <= b) {
    itvs[x].insert(v);
    return;
  }
  int M = (A + B) / 2;
  insert(2 * x, A, M, a, b, v);
  insert(2 * x + 1, M, B, a, b, v);
}

void erase(int x, int A, int B, int a, int b, int v) {
  if(b <= A || B <= a) return;
  if(a <= A && B <= b) {
    itvs[x].erase(v);
    return;
  }
  int M = (A + B) / 2;
  erase(2 * x, A, M, a, b, v);
  erase(2 * x + 1, M, B, a, b, v);
}

void query(int x, int A, int B, int a, int b, set<int>& res) {
  if(b <= A || B <= a) return;
  for(typeof(itvs[x].begin()) it = itvs[x].begin(); it != itvs[x].end(); it++) {
    res.insert(*it);
  }
  if(a <= A && B <= b) {
    return;
  }

  int M = (A + B) / 2;
  query(2 * x, A, M, a, b, res);
  query(2 * x + 1, M, B, a, b, res);
}

int main() {
  int N; cin >> N;

  int ind = 0;

  vector<pair<int, pair<int, int> > > cmds;

  vector<int> xs;
  for(int i = 0; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if(x == 2) {
      y--; z--;
    } else {
      xs.push_back(y);
      xs.push_back(y + 1);
      xs.push_back(z);
      xs.push_back(z + 1);
    }
    cmds.push_back(make_pair(x, make_pair(y, z)));
  }

  sort(xs.begin(), xs.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

  for(int i = 0; i < N; i++) {
    if(cmds[i].first == 1) {
      cmds[i].second.first = lower_bound(xs.begin(), xs.end(),
                                         cmds[i].second.first) - xs.begin();
      cmds[i].second.second = lower_bound(xs.begin(), xs.end(),
                                          cmds[i].second.second) - xs.begin();
    }
  }

  for(int i = 0; i < N; i++) {
    int c = cmds[i].first;
    if(c == 1) {
      P[ind] = ind;
      A[ind] = cmds[i].second.first;
      B[ind] = cmds[i].second.second;
      OA[ind] = A[ind];
      OB[ind] = B[ind];

      set<int> st;
      int nind = ind++;
      query(1, 0, 1 << 18, A[nind], A[nind] + 1, st);
      query(1, 0, 1 << 18, B[nind], B[nind] + 1, st);

      for(typeof(st.begin()) it = st.begin(); it != st.end(); ++it) {
        erase(1, 0, 1 << 18, A[*it] + 1, B[*it], *it);
        nind = merge(*it, nind);
      }


      if(A[nind] + 1 < B[nind]) {
        insert(1, 0, 1 << 18, A[nind] + 1, B[nind], nind);
      }
    } else {
      int v0 = cmds[i].second.second;
      int v1 = cmds[i].second.first;

      v0 = find(v0);
      if(v0 == find(v1) || (A[v0] < OA[v1] && OA[v1] < B[v0]) ||
                           (A[v0] < OB[v1] && OB[v1] < B[v0])) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}