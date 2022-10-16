#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;
using pint = pair<int, int>;

constexpr int N = 2e5, B = 30;

vector<int> a;
vector<pint> m;
set<pint> s;
int prv[B][N], nxt[B][N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    int64_t ans = 0;
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(a));
    for (int b = 0; b < B; ++b) {
        for (int j = 0; j < n; ++j)
            prv[b][j] = a[j] & (1 << b)? j: j? prv[b][j - 1]: -1;
        for (int j = n - 1; j > -1; --j)
            nxt[b][j] = a[j] & (1 << b)? j: j < n - 1? nxt[b][j + 1]: n;
    }
    for (int i = 0; i < n; ++i)
        m.push_back({a[i], i});
    sort(all(m));
    reverse(all(m));
    s.insert({-1, n});
    for (auto i: m) {
        auto sgm = *prev(s.upper_bound({i.second, n}));
        int l = sgm.first, r = sgm.second;
        for (int b = 0; b < B; ++b) if (!(i.first & (1 << b)))
            l = max(l, prv[b][i.second]),
            r = min(r, nxt[b][i.second]);
        ans += (i.second - l) * int64_t(r - i.second);
        s.erase(sgm);
        s.insert({{sgm.first, i.second}, {i.second, sgm.second}});
    }
    cout << n * (n + 1ll) / 2 - ans;
    return 0;
}