#include <iostream>

using namespace std;

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s >> s;
    for (auto c: s) {
      if (c == 'D' || c == 'U') {
        cout.put(c ^ 'D' ^ 'U');
      } else {
        cout.put(c);
      }
    }
    cout << '\n';
  }
  return 0;
}