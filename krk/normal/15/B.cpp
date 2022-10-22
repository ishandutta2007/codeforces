#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll t, n, m;

int main()
{
    ll x1, x2, y1, y2, dx, dy;
    ll top1, bot1, lef1, rig1, top2, bot2, lef2, rig2, top3, bot3, lef3, rig3, s1, s2, s3;
    cin >> t;
    while (t--) {
          cin >> n >> m >> x1 >> y1 >> x2 >> y2;
          dx = x2 - x1; dy = y2 - y1;
          top1 = max(0LL, -dx); bot1 = min(n-1, n-1-dx);
          lef1 = max(0LL, -dy); rig1 = min(m-1, m-1-dy);
          top2 = max(0LL, dx); bot2 = min(n-1, n-1+dx);
          lef2 = max(0LL, dy); rig2= min(m-1, m-1+dy);
          top3 = max(top1, top2); bot3 = min(bot1, bot2);
          lef3 = max(lef1, lef2); rig3 = min(rig1, rig2);
          s1 = (bot1 - top1 + 1LL) * (rig1 - lef1 + 1LL);
          s2 = (bot2 - top2 + 1LL) * (rig2 - lef2 + 1LL);
          s3 = (bot3 - top3 + 1LL) * (rig3 - lef3 + 1LL);
          if (top3 <= bot3 && lef3 <= rig3)
             cout << m*n - (s1 + s2 - s3) << endl;
          else cout << m*n - s1 - s2 << endl;
    }
    return 0;
}