#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (!count(s.begin(), s.end(), '0')) {
      cout << "0\n";
    } else if (!count(s.begin(), s.end(), '1') || count(s.begin(), s.end(), '0') == s.rfind('0') - s.find('0') + 1) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
  return 0;
}