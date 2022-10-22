#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const ld pi = acos(-1.0l);

int T;
int n;

ld Len(const ldld &a, const ldld &b) { return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); }

ldld Avg(const ldld &a, const ldld &b) { return ldld((a.first + b.first) / 2, (a.second + b.second) / 2); }

ldld Get(int wh)
{
    return ldld(cos(ld(wh) * 2 * pi / n), sin(ld(wh) * 2 * pi / n));
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); n *= 2;
        ld mult = 1 / Len(Get(0), Get(1));
        ldld p1 = Avg(Get(0), Get(1));
        ldld p2 = Avg(Get(n / 2), Get(n / 2 + 1));
        cout << fixed << setprecision(15) << mult * Len(p1, p2) << endl;
    }
    return 0;
}