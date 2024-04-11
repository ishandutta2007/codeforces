#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template<typename T, typename U> inline void relaxmin( T &res, const U &x ) { if ( x < res ) res = x; }
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define ZERO(v) memset(v, 0, sizeof v)

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<pair<int, int> > output_edges;

int depth[MAXN], lowlink[MAXN];

void rek(int a, int parent) {
  lowlink[a] = depth[a];

  for (int i=0; i<(int)adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b == parent) {
      continue;
    }

    if (depth[b]) {
      if (depth[b] < depth[a]) {
        output_edges.push_back(make_pair(a, b));
        relaxmin(lowlink[a], depth[b]);
      }
    } else {
      output_edges.push_back(make_pair(a, b));
      depth[b] = depth[a]+1;
      rek(b, a);
      if (lowlink[b] > depth[a]) {
        throw 1;
      }
      relaxmin(lowlink[a], lowlink[b]);
    }
  }
}

int main() {
  cin.sync_with_stdio(0);

  int V, E;
  cin >> V >> E;
  while (E-- > 0) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  try {
    ZERO(depth);
    depth[1] = 1;
    rek(1, -1);
    foreach (it, output_edges) {
      cout << it->first << ' ' << it->second << endl;
    }
  } catch (int x) {
    cout << 0 << endl;
  }

  return 0;
}