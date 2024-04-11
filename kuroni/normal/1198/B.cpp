#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int n, q, t, p, x;
pair<int, int> a[N];
vector<pair<int, int>> all;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].se;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> p;
            cin >> a[p].se;
            a[p].fi = i;
        }
        else
        {
            cin >> x;
            while (!all.empty() && all.back().se <= x)
                all.pop_back();
            all.push_back({i, x});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        auto it = upper_bound(all.begin(), all.end(), make_pair(a[i].fi, 0));
        if (it == all.end() || it->se < a[i].se)
            cout << a[i].se << " ";
        else
            cout << it->se << " ";
    }
}