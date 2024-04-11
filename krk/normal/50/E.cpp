#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 10000000;
const ld sm = 0.000000001;

int n, m;
ll ans;

int main()
{
    cin >> n >> m;
    for (int b = 1; b <= n; b++) 
       if (ll(m) >= ll(b) * ll(b)) ans += (ll) 2 * b * (b - 1);
       else ans += 2 * (m - int(sqrt(ld(b)*ld(b)-ld(1))+sm) + int(sqrt(ld(b)*ld(b)-ld(m)-ld(1))+sm));
    for (int x = -Maxn; x < 0; x++)
       for (int k = -1; k * x <= m; k--)
          if (-(x + k) % 2 == 0 && -(x + k) / 2 <= n) { ans++; break; }
    cout << ans << endl;
    return 0;
}