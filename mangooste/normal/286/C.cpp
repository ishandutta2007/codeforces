#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> p, st;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  p.resize(n);
  for (auto &el : p) {
    cin >> el;
  }
  int t;
  cin >> t;
  while (t--) {
    int pos;
    cin >> pos;
    pos--;
    p[pos] = -abs(p[pos]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (p[i] > 0 && !st.empty() && abs(p[st.back()]) == p[i]) {
      st.pop_back();
    } else {
      p[i] = -abs(p[i]);
      st.push_back(i);
    }
  }
  if (!st.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto el : p) {
      cout << el << ' ';
    }
    cout << '\n';
  }
}