#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tr1/unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )
template<typename Set, typename Element> inline bool inset( const Set &S, const Element &E ) { return S.find(E) != S.end(); }
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

struct Hasher {
  unsigned operator()(const pair<int, int> &p) const {
    return p.first * 100003 + p.second;
  }
};

tr1::unordered_set<pair<int, int>, Hasher> edges;
vector<int> unvisited;

void bfs(int a, vector<int> &comp) {
  static queue<int> q;
  assert(q.empty());
  q.push(a);

  while (!q.empty()) {
    int a = q.front(); q.pop();
    comp.push_back(a);

    for (int i=0; i<(int)unvisited.size(); ++i) {
      int b = unvisited[i];
      if (!inset(edges, make_pair(a, b))) {
        q.push(b);
        swap(unvisited[i], unvisited.back());
        unvisited.pop_back();
        --i;
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(0);

  int V, E;
  cin >> V >> E;
  repeat (E) {
    int a, b;
    cin >> a >> b;
    edges.insert(make_pair(a, b));
    edges.insert(make_pair(b, a));
  }

  for (int i=1; i<=V; ++i) {
    unvisited.push_back(i);
  }
  random_shuffle(unvisited.begin(), unvisited.end());
  vector<vector<int> > components;
  components.reserve(V);
  while (!unvisited.empty()) {
    int src = unvisited.back(); unvisited.pop_back();
    components.push_back(vector<int>());
    bfs(src, components.back());
  }

  cout << components.size() << '\n';
  foreach (it, components) {
    cout << it->size();
    foreach (jt, *it) {
      cout << ' ' << *jt;
    }
    cout << '\n';
  }
  
  return 0;
}