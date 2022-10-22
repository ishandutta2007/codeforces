#include <iostream>
using namespace std;

typedef long long ll;

ll t1, t2, x1, x2, t0;
ll s1, v1;
ll y1, y2;
ll c1, c2;

void Find(ll l, ll r)
{
     if (l > r) return;
     ll mid = (l + r) / 2LL;
     if (t0 * (c1 + mid) <= (t1 * c1 + t2 * mid)) {
            c2 = mid;
            Find(l, mid - 1);
     } else Find(mid + 1, r);
}

int main()
{
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    s1 = t2 * x2; v1 = x2;
    y1 = 0; y2 = x2;
    c1 = x1; c2 = x2;
    while (c1 >= 0 && c2 >= 0 && (c1 || c2)) {
          ll s2 = t1 * c1 + t2 * c2;
          ll v2 = c1 + c2;
          if (t0 * v2 < s2) {
                 if (s2 * v1 < s1 * v2) {
                        s1 = s2; v1 = v2;
                        y1 = c1; y2 = c2;
                 }
                 c2--;
          } else if (t0 * v2 > s2) c1--;
          else {
               y1 = c1; y2 = c2;
               break;
          }
    }
    cout << y1 << " " << y2 << endl;
    return 0;
}