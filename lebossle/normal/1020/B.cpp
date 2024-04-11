#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> next(n);
  for (int i=0; i<n; ++i) {
    cin >> next[i];
    next[i]--;
  }
  for (int f=0; f<n; ++f) {
    vector<bool> vis(n, false);
    int cur = f;
    while (!vis[cur]) {
      vis[cur] = true;
      cur = next[cur];
    }
    cout << (f==0 ? "" : " ") << cur+1;
  }
  cout << endl;
}