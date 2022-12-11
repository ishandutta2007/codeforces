#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n+2);
  v[0] = 0;
  v[n+1] = 1001;
  for (int i=1; i<=n; ++i)
    cin >> v[i];
  int cur=0, ans=0;
  for (int i=1; i<=n; ++i) {
    if (v[i]-v[i-1] == 1 && v[i+1]-v[i] == 1)
      cur++;
    else
      cur=0;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}