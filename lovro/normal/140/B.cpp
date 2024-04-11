#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

int n;
int solve(int id, const vector<int> &fri, const vector<int> &alex_pri) {
  vector<char> alex_can_send(n+1, 0);

  int now = -1;
  for (int i=1; i<=n; ++i) {
    if (i == id) {
      continue;
    }

    if (now == -1 || alex_pri[i] < alex_pri[now]) {
      now = i;
      alex_can_send[i] = 1;
    }
  }
  
  foreach (it, fri) {
    if (alex_can_send[*it]) {
      return *it;
    }
  }
  abort();
}

int main() {
  cin.sync_with_stdio(0);

  cin >> n;

  vector<vector<int> > friends(n+1);
  for (int i=1; i<=n; ++i) {
    friends[i].resize(n);
    for (int j=0; j<n; ++j) {
      cin >> friends[i][j];
    }
  }

  vector<int> alex_pri(n+1);
  for (int i=0; i<n; ++i) {
    int x;
    cin >> x;
    alex_pri[x] = i;
  }

  for (int i=1; i<=n; ++i) {
    if (i > 1) {
      cout << ' ';
    }
    cout << solve(i, friends[i], alex_pri);
  }
  cout << '\n';

  return 0;
}