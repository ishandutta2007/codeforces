/*
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;

#define MAXN 100010
#define MAXL 17

int L[MAXN];
int P[MAXN][MAXL];

void fillin(int x, int dep) {
  while(1 << L[x] + 1 <= dep) {
    int nxt = P[x][L[x]];
    fillin(nxt, dep - (1 << L[x]));
    P[x][L[x] + 1] = P[nxt][L[x]];
    L[x]++;
  }
}

int depth(int x) {
  if(L[x] == -1) {
    return 0;
  }
  int dep = (1 << L[x]) + depth(P[x][L[x]]);
  fillin(x, dep);
  return dep;
}

void init(int N) {
  memset(L, -1, sizeof(L));
}

void make_parent(int u, int v) {
  P[v][0] = u;
  L[v] = 0;
}

bool is_ancestor(int u, int v) {
  int du = depth(u);
  int dv = depth(v);
  int diff = dv - du;
  if(diff < 0) {
    return false;
  }

  for(int i = 31 - __builtin_clz(diff); i >= 0; i--) {
    if(diff & 1 << i) {
      fillin(v, dv);
      v = P[v][i];
      dv -= 1 << i;
    }
  }
  return u == v;
}

int main() {
  int N, M;
  cin >> N >> M;
  init(N);

  vector<int> R;
  vector<vector<pair<int, int> > > queries;
  vector<pair<int, int> > cmds;
  for(int i = 0; i < M; i++) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      int x, y; cin >> x >> y; -- x; --y;
      cmds.push_back(make_pair(x, y));
    } else if (cmd == 2) {
      int x; cin >> x; --x;
      cmds.push_back(make_pair(x, -1));
      queries.resize(queries.size() + 1);
    } else {
      int x, ind; cin >> x >> ind; --x; --ind;
      queries[ind].push_back(make_pair(R.size(), x));
      R.resize(R.size() + 1);
    }
  }

  int pos = 0;
  for(int i = 0; i < cmds.size(); i++) {
    int x = cmds[i].first;
    int y = cmds[i].second;
    if (y == -1) {
      for(int j = 0; j < queries[pos].size(); j++) {
        int ind = queries[pos][j].first;
        int nd = queries[pos][j].second;
        R[ind] = is_ancestor(nd, x) ? 1 : 2;
      }
      pos++;
    } else {
      make_parent(y, x);
    }
  }

  for(int i = 0; i < R.size(); i++) {
    if (R[i] == 0) {
      cout << "ERR" << endl;
    } else if (R[i] == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}