#include <iostream>

using namespace std;

constexpr int N = 2e5;

int k[N];

int main()
{
    int t, a, b;
    cin >> t;
    do {
      cin >> a >> b;
      int g = a + b, s = 0;
      for (auto sa: {(g + 1) / 2, g / 2}) {
        int sb = g - sa;
        for (int ha = 0; ha <= min(a, sa); ++ha) {
          int ba = sa - ha, bb = a - ha, hb = sb - bb;
          if (ba >= 0 && bb >= 0 && hb >= 0 && k[ba + bb] != t) {
            ++s;
            k[ba + bb] = t;
          }
        }
      }
      cout << s << '\n';
      for (int i = 0; i <= g; ++i) if (k[i] == t) {
        cout << i << ' ';
      }
      cout << '\n';
    } while (--t);
    return 0;
}