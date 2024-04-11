#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#define pb push_back
#define all(a) begin(a), end(a)

using namespace std;

int powmod(int a, int p, int m)
{
    int64_t ans = 1, cp = a;
    for (int i = 0; (1ll << i) <= p; ++i, cp = cp * cp % m)
        if ((1ll << i) & p)
            ans = ans * cp % m;
    return ans;
}

int divmod(int64_t a, int b, int m)
{
    return a * powmod(b, m - 2, m) % m;
}

const int N = 200000;
int a[N], t[N], b[N], n, m;
unordered_set<int> pres;
vector<int> s;
double et;

pair<int, int> solve()
{
    for (int i = 0; i < n; ++i)
        s.pb((a[i] - a[0] + m) % m);
    sort(all(s));
    int dst = 0;
    for (int i = 0; i < n; ++i)
    {
        auto t = lower_bound(all(s), (a[i] - a[1] + m) % m);
        if (t == s.end() || *t != (a[i] - a[1] + m) % m)
            dst++;
    }
    int d = divmod((a[1] - a[0] + m) % m, dst, m), heads = 0;
    for (int i = 0; i < n; ++i)
        heads += !pres.count((a[i] + d) % m);
    if (!~-heads)
    for (int i = 0; i < n; ++i)
        if (!pres.count((a[i] + d) % m))
            return {a[i], (m - d) % m};
    return {-1, -1};
}

int main()
{
    srand(101);
    cin.tie(0), ios::sync_with_stdio(0);
    int comp = 0;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1 || n == m)
        return cout << a[0] << ' ' << 1, 0;
    if (n > m - n)
    {
        sort(a, a + n);
        for (int i = 0; i < m; ++i) t[i] = i;
        memcpy(a, b, (set_difference(t, t + m, a, a + n, b) - b) * sizeof * b);
        comp = 1;
        n = m - n;
    }
    for (int i = 0; i < n; ++i)
        pres.insert(a[i]);
    auto ans = solve();
    if (!~ans.first)
        cout << "-1";
    else if (!comp)
        cout << ans.first << ' ' << ans.second << '\n';
    else
        cout << (ans.first - ans.second + m) % m << ' ' << (m - ans.second) % m << '\n';
    return 0;
}