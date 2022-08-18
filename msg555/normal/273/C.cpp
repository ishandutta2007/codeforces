#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> E[300010];
int EN[300010];

set<pair<int, int> > st;

void adjust(int u, int en) {
  st.erase(make_pair(-EN[u], u));
  EN[u] = en;
  st.insert(make_pair(-en, u));
}

int main() {
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  string S(N, '0');
  for(int i = 0; i < N; i++) {
    EN[i] = E[i].size();
    st.insert(make_pair(-E[i].size(), i));
  }

  while(st.begin()->first < -1) {
    int u = st.begin()->second;

    S[u] = S[u] == '0' ? '1' : '0';
    adjust(u, E[u].size() - EN[u]);
    for(int i = 0; i < E[u].size(); i++) {
      int v = E[u][i];
      adjust(v, EN[v] + (S[v] == S[u] ? 1 : -1));
    }
  }

  cout << S << endl;
}