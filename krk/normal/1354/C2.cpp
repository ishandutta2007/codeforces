#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const ld pi = acos(-1.0l);
const ld Inf = 1e3;

int T;
int n;

ld Len(const ldld &a, const ldld &b) { return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); }

ldld Avg(const ldld &a, const ldld &b, int coefa, int coefb) { return ldld((a.first * coefa + b.first * coefb) / (coefa + coefb), (a.second * coefa + b.second * coefb) / (coefa + coefb)); }

ldld Get(int wh, ld ch)
{
    return ldld(cos(ld(wh) * 2 * pi / n + ch), sin(ld(wh) * 2 * pi / n + ch));
}

ld Try(ld ch, ld mult)
{
    ld mnx = Inf, mxx = -Inf;
    ld mny = Inf, mxy = -Inf;
    for (int i = 0; i < n; i++) {
        auto got = Get(i, ch);
        mnx = min(mnx, got.first);
        mxx = max(mxx, got.first);
        mny = min(mny, got.second);
        mxy = max(mxy, got.second);
    }
     return mult * max(mxx - mnx, mxy - mny);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); n *= 2;
        ld mult = 1 / Len(Get(0, 0.0), Get(1, 0.0));
        ld lim = 2 * pi / n;
        ld best = Try(lim / 1000000 * 250000, mult);
        cout << fixed << setprecision(15) << best << endl;
    }
    return 0;
}