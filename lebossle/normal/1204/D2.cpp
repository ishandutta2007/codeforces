#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = s;
  int st = 0;
  for (int i=s.size()-1; i>=0; --i) {
    if (st == 0)
      ans[i] = '0';
    st = max(0, st + (s[i] == '0' ? 1 : -1));
  }
  cout << ans << endl;
}