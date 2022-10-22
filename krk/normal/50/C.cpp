#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 10000000000000LL;

int main()
{
    ll l, u, r, d;
    int n, x, y;
    l = d = Inf; u = r = -Inf;
    scanf("%d", &n);
    while (n--) {
          scanf("%d %d", &x, &y);
          d = min(d, (ll)x + y);
          u = max(u, (ll)x + y);
          l = min(l, (ll)x - y);
          r = max(r, (ll)x - y);
    }
    printf("%I64d\n", u - d + r - l + 4LL);
    return 0;
}