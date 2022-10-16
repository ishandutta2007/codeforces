#include <iostream>

using namespace std;

int main()
{
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s >> s;
    auto z = s.find('0');
    if (z == s.npos) {
      cout << "1 " << s.size() / 2 * 2 << " 1 " << s.size() / 2 << '\n';
    } else if (z >= s.size() / 2) {
      cout << "1 " << z + 1 << " 1 " << z << '\n';
    } else {
      cout << z + 1 << ' ' << s.size() << ' ' << z + 2 << ' ' << s.size() << '\n';
    }
  }
  return 0;
}