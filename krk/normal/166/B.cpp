#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 100005;
const ld eps = 1e-4;

int n;
int Ax[Maxn], Ay[Maxn];
int m;
bool ok = true;

ll Cross(ll ax, ll ay, ll bx, ll by) { return ax * by - ay * bx; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &Ax[i], &Ay[i]);
    scanf("%d", &m);
    while (m-- && ok) {
        int Bx, By; scanf("%d %d", &Bx, &By);
        int bx = Bx - Ax[0], by = By - Ay[0];
        int res = 0;
        int l = 1, r = n - 1;
        while (l <= r) {
            int m = l + r >> 1;
            int ax = Ax[m] - Ax[0], ay = Ay[m] - Ay[0];
            if (Cross(bx, by, ax, ay) >= 0LL) { res = m; l = m + 1; }
            else r = m - 1;
        }
        if (!res || res == n - 1) { ok = false; break; }
        if (res == 1 && Cross(bx, by, Ax[1] - Ax[0], Ay[1] - Ay[0]) == 0LL) { ok = false; break; }
        if (Cross(Bx - Ax[res], By - Ay[res], Ax[res + 1] - Ax[res], Ay[res + 1] - Ay[res]) <= 0LL) {
            ok = false; break;
        }
    }
    printf(ok? "YES\n": "NO\n");
    return 0;
}