#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int T;
int n;

ll Ask(int l, int r)
{
    printf("? %d %d\n", l, r); fflush(stdout);
    ll res; scanf("%I64d", &res);
    return res;
}

int Solve(ll val)
{
    ll got = 1ll + 8ll * val;
    ll ans = sqrt(ld(got));
    while (ans * ans > got) ans--;
    while (ans * ans < got) ans++;
    if (ans * ans != got) return -1;
    ans++;
    if (ans % 2) return -1;
    return ans / 2;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll tot = Ask(1, n);
        int l = 2, r = n;
        int L = -1, R = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (L == -1) {
                ll got = Ask(1, mid - 1);
                if (got == 0) { l = mid + 1; continue; }
                if (got == tot) { r = mid - 1; continue; }
                int my = Solve(got);
                if (my == -1) { r = mid - 1; continue; }
                if (mid - my < 1) { r = mid - 1; continue; }
                if (Ask(mid - my, mid - 1) != got) { r = mid - 1; continue; }
                L = mid - my;
                continue;
            }
            if (R == -1) {
                ll got = Ask(mid, n);
                if (got == 0) { r = mid - 1; continue; }
                if (got == tot) { l = mid + 1; continue; }
                int my = Solve(got);
                if (my == -1) { l = mid + 1; continue; }
                if (mid + my - 1 > n) { l = mid + 1; continue; }
                if (Ask(mid, mid + my - 1) != got) { l = mid + 1; continue; }
                R = mid + my - 1;
                continue;
            }
            ll got = Ask(1, mid - 1);
            if (Solve(got) != mid - L) { r = mid - 1; continue; }
            if (Solve(tot - got) != R - mid + 1) { l = mid + 1; continue; }
            got = Ask(mid, n);
            if (Solve(got) != R - mid + 1) { l = mid + 1; continue; }
            if (Solve(tot - got) != mid - L) { r = mid - 1; continue; }
            printf("! %d %d %d\n", L, mid, R); fflush(stdout);
            break;
        }
    }
    return 0;
}