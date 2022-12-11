#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}

map<char, int> winId{
  {'R', 1},
  {'P', 2},
  {'S', 0}
};

map<char, int> mId{
  {'R', 0},
  {'P', 1},
  {'S', 2}
};

const string moves="RPS";

void solve() {
  int n;
  cin >> n;
  vector<int> v(3);
  for (int& i : v)
    cin >> i;
  string s;
  cin >> s;
  int ansAmt=0;
  string ans(n, '-');
  for (int i=0; i<n; ++i) {
    int id = winId[s[i]];
    if (v[id] > 0) {
      ansAmt++;
      v[id]--;
      ans[i] = moves[id];
    }
  }
  if (ansAmt < (n+1)/2) {
    cout << "NO" << '\n';
    return;
  }
  for (int i=0; i<n; ++i) {
    int id = mId[s[i]];
    if (ans[i] == '-' && v[id] > 0) {
      v[id]--;
      ans[i] = moves[id];
    }
  }
  for (int i=0; i<n; ++i)
    if (ans[i] == '-')
      for (int j=0; j<4; ++j)
        if (v[j]>0) {
          v[j]--;
          ans[i] = moves[j];
        }
  cout << "YES" << '\n';
  cout << ans << '\n';
}