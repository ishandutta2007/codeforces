#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  int t;
  string s, u;
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> s >> s;
    u = s;
    sort(u.begin(), u.end());
    for (int i = 0; i < s.size(); ++i) {
      ans += s[i] != u[i];
    }
    cout << ans << '\n';
  }
  return 0;
}