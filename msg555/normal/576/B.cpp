#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> PI(N);
  for (int i = 0; i < N; i++) {
    cin >> PI[i];
    PI[i]--;
  }

  vector<bool> vis(N, false);
  vector<vector<int> > cycs;
  for (int i = 0; i < N; i++) {
    if (vis[i]) continue;

    vector<int> cyc;
    for (int x = i; !vis[x]; x = PI[x]) {
      cyc.push_back(x);
      vis[x] = true;
    }
    cycs.push_back(cyc);
  }

  sort(cycs.begin(), cycs.end(), [](const vector<int>& A, 
                                    const vector<int>& B) {
    return A.size() < B.size();
  });

  if (cycs[0].size() == 1) {
    cout << "YES\n";
    for (int i = 0; i < N; i++) {
      if (i == cycs[0][0]) {
        continue;
      }
      cout << cycs[0][0] + 1 << ' ' << i + 1 << '\n';
    }
  } else if (cycs[0].size() == 2) {
    for (int i = 0; i < cycs.size(); i++) {
      if (cycs[i].size() % 2 != 0) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    cout << cycs[0][0] + 1 << ' ' << cycs[0][1] + 1 << '\n';
    for (int i = 1; i < cycs.size(); i++) {
      for (int j = 0; j < cycs[i].size(); j++) {
        cout << cycs[0][j % 2] + 1 << ' ' << cycs[i][j] + 1 << '\n';
      }
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}