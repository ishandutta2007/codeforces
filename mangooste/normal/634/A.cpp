#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> a, b;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x != 0) {
      a.push_back(x);
    }
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x != 0) {
      b.push_back(x);
    }
  }
  rotate(a.begin(), find(a.begin(), a.end(), 1), a.end());
  rotate(b.begin(), find(b.begin(), b.end(), 1), b.end());
  cout << (a == b ? "YES\n" : "NO\n");
}