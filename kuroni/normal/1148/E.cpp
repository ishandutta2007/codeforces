#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
using namespace std;

const int N = 300005;

int n, b[N];
pair<int, int> a[N];
vector<pair<int, int>> ve;
vector<pair<pair<int, int>, int>> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i].fi < b[i])
            ve.push_back({b[i] - a[i].fi, a[i].se});
        else
        {
            while (a[i].fi > b[i] && !ve.empty())
                if (a[i].fi - b[i] >= ve.back().fi)
                {
                    ans.push_back({{ve.back().se, a[i].se}, ve.back().fi});
                    a[i].fi -= ve.back().fi;
                    ve.pop_back();
                }
                else
                {
                    ans.push_back({{ve.back().se, a[i].se}, a[i].fi - b[i]});
                    ve.back().fi -= a[i].fi - b[i];
                    a[i].fi = b[i];
                }
            if (a[i].fi > b[i])
                return cout << "NO", 0;
        }
    if (!ve.empty())
        return cout << "NO", 0;
    else
    {
        cout << "YES\n" << ans.size() << '\n';
        for (auto v : ans)
            cout << v.fi.fi << " " << v.fi.se << " " << v.se << '\n';
    }
}