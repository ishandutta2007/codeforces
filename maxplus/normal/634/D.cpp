#define first f
#define second s
#include <algorithm>
#include <iostream>
#include <vector>
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 200001;
int d, a, n, nx[N];
vector<pair<int, int>> v;
pair<int, int> g[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> d >> a >> n;
    for (int i = 0; i < n; ++i)
        cin >> g[i].f >> g[i].s;
    sort(g, g + n);
//    nx[n - 1] = x[n - 1] + n + 1;
//    v.pb({p[n - 1], x[n - 1]});
    for (int i = n - 1; i > -1; --i)
    {
        auto it = upper_bound(all(v), make_pair(g[i].s, -1));
        if (it == v.begin())
            nx[i] = d;
        else
            nx[i] = (--it)->s;
        while (v.size() && v.back().f > g[i].s)
            v.pop_back();
        v.push_back({g[i].s, g[i].f});
    }
    int64_t l = a, c = 0;
    for (int i = 0; i < n; ++i)
    {
        if (l < g[i].f)
            return cout << -1, 0;
        int nl = max(l + 0ll, min(nx[i] + 0ll, g[i].f + a + 0ll));
        c += (nl - l) * g[i].s;
        l = nl;
    }
    if (l < d)
        return cout << -1, 0;
    cout << c;
    return 0;
}