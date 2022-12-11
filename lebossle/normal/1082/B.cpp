#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> sz;
  int cur = 0, sum = 0;
  for (int i=0; i<n; ++i) {
    if (s[i] == 'S') {
      sz.push_back(cur);
      cur = 0;
    } else {
      cur++;
      sum++;
    }
  }
  sz.push_back(cur);
  int ans=0;
  for (int i=0; i<sz.size(); ++i) {
    if (sz[i] == sum) {
      ans = sum;
      break;
    }
    ans = max(ans, min(sum, sz[i]+1));
    if (i > 0)
      ans = max(ans, min(sum, sz[i-1]+1+sz[i]));
  }
  cout << ans << endl;
}