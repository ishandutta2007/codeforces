#include <bits/stdc++.h>

using namespace std;

vector<string> names;
set<string> s;

void solve() {
  int n; cin >> n;

  string name; 
  for (int i = 0; i < n; i++) {
    cin >> name;
    names.push_back(name);
  }

  reverse(names.begin(), names.end());
  for (const string &name : names) {
    if (s.find(name) == s.end()) {
      s.insert(name);

      cout << name << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}