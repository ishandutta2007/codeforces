#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const int Maxn = 100005;
const ld Inf = 1e300l;

int n;
int X[Maxn], Y[Maxn];
ld res;

ldld Solve(ld x)
{
    ldld res = ldld(0, 0);
    for (int i = 0; i < n; i++) {
        ld val = (X[i] - x) * (X[i] - x) / (2 * Y[i]) + Y[i] / 2.0l;
        if (X[i] <= x) res.first = max(res.first, val);
        else res.second = max(res.second, val);
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    bool a = false, b = false;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        a |= Y[i] > 0;
        b |= Y[i] < 0;
    }
    if (a && b) { printf("-1\n"); return 0; }
    if (b)
        for (int i = 0; i < n; i++)
            Y[i] = -Y[i];

    ld lef = -10000000, rig = 10000000;
    for (int i = 0; i < 100; i++) {
        ld mid = (lef + rig) / 2.0l;
        ldld got = Solve(mid);
        if (got.first >= got.second) {
            res = got.first;
            rig = mid;
        } else {
            res = got.second;
            lef = mid;
        }
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}