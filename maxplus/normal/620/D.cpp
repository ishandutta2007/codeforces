#define first f
#define second s
#include <iostream>
#include <cmath>
#include <map>
#undef first
#undef second

using namespace std;

int64_t n, m, dif, a1, a2, a1a, a1b, a[3000], b[3000];
pair<int64_t, int64_t> a2a, a2b;
map<int64_t, int64_t> s;
map<int64_t, pair<int64_t, int64_t>> d;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], dif += a[i];
    cin >> m;
    for (int j = 0; j < m; ++j)
        cin >> b[j], dif -= b[j];
    a1 = a2 = abs(dif) + 1;
    for (int i = 0; i < n; ++i)
        s[a[i]] = i;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
        d[a[i] + a[j]] = {j, i};
    for (int j = 0; j < m; ++j)
    {
        auto it = s.upper_bound(b[j] + dif / 2);
//        if (b[j] + dif / 2 > 2e9 + 1)
//            it = s.end();
        if (it != s.end())
            if (a1 > abs(dif + 2 * (b[j] - it->f)))
                a1 = abs(dif + 2 * (b[j] - it->f)), a1a = it->s, a1b = j;
        if (it != s.begin())
            if (a1 > abs(dif + 2 * (b[j] - (--it)->f)))
                a1 = abs(dif + 2 * (b[j] - it->f)), a1a = it->s, a1b = j;
    }
    for (int j = 0; j < m; ++j)
    for (int i = 0; i < j; ++i)
    {
        auto it = d.upper_bound(b[j] + b[i] + dif / 2);
//        if (b[j] + dif / 2 > 2e9 + 1)
//            it = d.end();
        if (it != d.end())
            if (a2 > abs(dif + 2 * (b[j] + b[i] - it->f)))
                a2 = abs(dif + 2 * (b[j] + b[i] - it->f)), a2a = it->s, a2b = {i, j};
        if (it != d.begin())
            if (a2 > abs(dif + 2 * (b[j] + b[i] - (--it)->f)))
                a2 = abs(dif + 2 * (b[j] + b[i] - it->f)), a2a = it->s, a2b = {i, j};
    }
    if (abs(dif) <= a1 && abs(dif) <= a2)
        cout << abs(dif) << "\n0";
    else if (a1 <= a2)
    {
        cout << a1 << "\n1\n";
        cout << a1a + 1 << ' ' << a1b + 1;
    }
    else
    {
        cout << a2 << "\n2\n";
        cout << a2a.f + 1 << ' ' << a2b.f + 1 << '\n';
        cout << a2a.s + 1 << ' ' << a2b.s + 1 << '\n';
    }
    return 0;
}