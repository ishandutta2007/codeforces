#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int v1 = 2;
  for (int i=3; i<=n; ++i) {
    cout << "2 1 " << v1 << ' ' << i << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
      v1 = i;
  }
  vector<lli> h(n+1, 0);
  for (int i=2; i<=n; ++i)
    if (i != v1) {
      cout << "1 1 " << v1 << ' ' << i << endl;
      cin >> h[i];
    }
  int top = 2;
  for (int i=3; i<=n; ++i)
    if (h[i] > h[top])
      top = i;
  vector<int> half(n+1, 0);
  for (int i=2; i<=n; ++i)
    if (i != v1 && i != top) {
      cout << "2 1 " << top << ' ' << i << endl;
      cin >> half[i];
    }
  half[v1] = -1;
  vector<int> ans(n-1);
  for (int i=2; i<=n; ++i)
    ans[i-2] = i;
  sort(ans.begin(), ans.end(), [&](int a, int b) {
    if (half[a] != half[b])
      return half[a] < half[b];
    if (half[a] == -1)
      return h[a] < h[b];
    else
      return h[a] > h[b];
  });
  cout << "0 1";
  for (int i : ans)
    cout << ' ' << i;
  cout << endl;
}