#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int l, r;
ll m;

void Solve()
{
    for (int a = l; a <= r; a++) {
        ll mx = (m + r - l) / a;
        if (mx <= 0) continue;
        ll got = mx * a;
        if (m + l - r <= got) {
            int b = l, c = l;
            if (got > m) c += got - m;
            else b += m - got;
            printf("%d %d %d\n", a, b, c);
            return;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %I64d", &l, &r, &m);
        Solve();
    }
    return 0;
}