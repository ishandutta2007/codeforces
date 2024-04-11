#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10005;
const int Inf = 2000000000;

int n, m;
int x, y;
int k;
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d", &x, &y);
    scanf("%d", &k);
    while (k--) {
        int dx, dy; scanf("%d %d", &dx, &dy);
        int pos1 = Inf, pos2 = Inf;
        if (dx > 0) pos1 = (n - x) / dx;
        else if (dx < 0) pos1 = (x - 1) / -dx;
        if (dy > 0) pos2 = (m - y) / dy;
        else if (dy < 0) pos2 = (y - 1) / -dy;
        int steps = min(pos1, pos2);
        res += steps;
        x += steps * dx; y += steps * dy;
    }
    printf("%I64d\n", res);
    return 0;
}