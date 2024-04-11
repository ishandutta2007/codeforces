#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
#define f first
#define s second

using namespace std;

typedef pair<int64_t, int64_t> pint;

int64_t operator*(pint a, pint b)
{
    return abs(a.f * b.s - a.s * b.f);
}

long double d(pint a, pint b, pint c)
{
    return pint{b.f - a.f, b.s - a.s} * pint{c.f - a.f, c.s - a.s} / hypotl(c.f - a.f, c.s - a.s) / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<pint> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].f >> v[i].s;
    v.pb(v[0]);
    v.pb(v[1]);
    long double ans = 2e9;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, d(v[i - 1], v[i], v[i + 1]));
    cout << fixed;
    cout.precision(30);
    cout << ans;
    return 0;
}