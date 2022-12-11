#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> v(n);
  for (int i=0; i<n; ++i) {
    int a;
    cin >> a;
    v[i] = c - a;
  }
  vector<int> amt0(n+1, 0);
  for (int i=0; i<n; ++i)
    amt0[i+1] = amt0[i] + (v[i]==0 ? 1 : 0);
  int ans = amt0.back();
  map<int, int> bestAmt;
  for (int i=0; i<n; ++i) {
    if (v[i] != 0) {
      bestAmt[v[i]] = max(amt0[i], bestAmt[v[i]]);
      bestAmt[v[i]]++;
      ans = max(ans, bestAmt[v[i]] - amt0[i] + amt0.back());
    }
  }
  cout << ans << endl;
}