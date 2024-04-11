#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define repeat(n) for ( int repc = (n); repc > 0; --repc )
#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

int main() {
  cin.sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int> > adj(n+1);
  repeat (m) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int result = 0;
  vector<char> alive(n+1, 1);
  for (;;) {
    vector<int> queue_die;

    for (int i=1; i<=n; ++i) {
      if (!alive[i]) {
        continue;
      }

      int degree = 0;
      for (int j=0; j<(int)adj[i].size(); ++j) {
        int b = adj[i][j];
        degree += alive[b];
      }
      if (degree == 1) {
        queue_die.push_back(i);
      }
    }

    if (queue_die.empty()) {
      break;
    }

    foreach (it, queue_die) {
      alive[*it] = 0;
    }
    ++result;
  }

  cout << result << endl;

  return 0;
}