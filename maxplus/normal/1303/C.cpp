#include <iostream>
#include <cstring>

using namespace std;

constexpr int let = 26;

int m[let][let];
int S[let];
int vis[let];

string ans;

void dfs(int l) {
  vis[l] = 1;
  ans += char(l + 'a');
  for (int i = 0; i < let; ++i) {
    if (m[l][i] && !vis[i]) {
      dfs(i);
    }
  }
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    memset(m, 0, sizeof m);
    memset(S, 0, sizeof S);
    memset(vis, 0, sizeof vis);
    ans = "";
    bool ok = 1;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
      m[s[i - 1] - 'a'][s[i] - 'a'] = m[s[i] - 'a'][s[i - 1] - 'a'] = 1;
    }
    for (int i = 0; i < let; ++i) {
      for (int j = 0; j < let; ++j) {
        S[i] += m[i][j];
      }
      if (S[i] > 2) {
        ok = 0;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < let; ++i) {
      if (S[i] < 2 && !vis[i]) {
        dfs(i);
      }
    }
    if (ans.size() < let) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n" << ans << "\n";
    }
}