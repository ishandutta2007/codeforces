#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c, x, y, z, k;
    cin >> x >> y >> z >> k;
    a = min(x - 1, k / 3);
    b = min(y - 1, k / 3);
    c = min(z - 1, k / 3);
    while (a + b + c < k && (a < x - 1 || b < y - 1 || c < z - 1)) {
          if (a == min(min(a, b), c) && a < x - 1) a++;
          else if (b == min(min(a, b), c) && b < y - 1) b++;
          else if (c == min(min(a, b), c) && c < z - 1) c++;
          else if ((a <= b || a <= c) && a < x - 1) a++;
          else if ((b <= a || b <= c) && b < y - 1) b++;
          else if ((c <= a || c <= b) && c < z - 1) c++;
          else if (a < x - 1) a++;
          else if (b < y - 1) b++;
          else if (c < z - 1) c++;
    }
    cout << (ll) (a + 1) * (b + 1) * (c + 1) << endl;
    return 0;
}