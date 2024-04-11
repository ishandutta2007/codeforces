/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, m, k, ans[100005], bit[100005];

struct point
{
    int x, y, z, i;
};

point l = {1000000, 1000000, 1000000, 0}, r = {0, 0, 0, 0};
vector<point> v;

void chmax(int pos, int val)
{
    for (int i = pos; i > 0; i -= (i & -i))
        bit[i] = max(bit[i], val);
}

int query(int pos)
{
    int ans = 0;
    for (int i = pos; i <= 100000; i += (i & -i))
        ans = max(bit[i], ans);
    return ans;
}

void solve()
{
    sort(v.begin(), v.end(), [](point p1, point p2)
         { return make_tuple(p1.x, p1.y, p1.z, -p1.i) > make_tuple(p2.x, p2.y, p2.z, -p2.i); });
    for (int i = 1; i <= 100000; i++)
        bit[i] = 0;
    for (auto &[x, y, z, i] : v)
        if (i)
            ans[i] |= (query(y) >= z);
        else if (x <= r.x && y <= r.y && z <= r.z)
            chmax(y, z);
}

signed main()
{
    fast;
    cin >> n >> m >> k >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        l.x = min(l.x, x);
        l.y = min(l.y, y);
        l.z = min(l.z, z);
        r.x = max(r.x, x);
        r.y = max(r.y, y);
        r.z = max(r.z, z);
    }
    v.resize(m + k);
    for (int i = 0; i < m; i++)
        cin >> v[i].x >> v[i].y >> v[i].z;
    for (int i = 1; i <= k; i++)
    {
        cin >> v[m + i - 1].x >> v[m + i - 1].y >> v[m + i - 1].z;
        v[m + i - 1].i = i;
    }
    for (auto &[x, y, z, i] : v)
        if (l.x <= x && x <= r.x &&
            l.y <= y && y <= r.y &&
            l.z <= z && z <= r.z)
        {
            ans[i] = 2;
            if (i == 0)
            {
                cout << "INCORRECT\n";
                return 0;
            }
        }
    cout << "CORRECT\n";
    for (int tx = 0; tx <= 1; tx++)
    {
        for (int ty = 0; ty <= 1; ty++)
        {
            for (int tz = 0; tz <= 1; tz++)
            {
                solve();
                for (auto &[x, y, z, i] : v)
                    z = 100001 - z;
                l.z = 100001 - l.z;
                r.z = 100001 - r.z;
                swap(l.z, r.z);
            }
            for (auto &[x, y, z, i] : v)
                y = 100001 - y;
            l.y = 100001 - l.y;
            r.y = 100001 - r.y;
            swap(l.y, r.y);
        }
        for (auto &[x, y, z, i] : v)
            x = 100001 - x;
        l.x = 100001 - l.x;
        r.x = 100001 - r.x;
        swap(l.x, r.x);
    }
    for (int i = 1; i <= k; i++)
        if (ans[i] == 0)
            cout << "UNKNOWN\n";
        else if (ans[i] == 1)
            cout << "CLOSED\n";
        else
            cout << "OPEN\n";
}