/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, order[300005], c[300005];
pair<pll, int> seg[1200005];
pll rmx[300005];

vector<ll> r;

void modify(pair<pll, int> p, int i = 1, int L = 1, int R = 300000)
{
    int mid = (L + R) / 2;
    if (p.F.F * mid + p.F.S > seg[i].F.F * mid + seg[i].F.S)
        swap(seg[i], p);
    if (L != R)
    {
        if (p.F.F >= seg[i].F.F)
            modify(p, i << 1 | 1, mid + 1, R);
        else
            modify(p, i << 1, L, mid);
    }
}

pll query(ll x, int i = 1, int L = 1, int R = 300000)
{
    int mid = (L + R) / 2;
    pll res = pll(seg[i].F.F * x + seg[i].F.S, seg[i].S);
    if (L == R)
        return res;
    else if (x <= mid)
        return max(res, query(x, i << 1, L, mid));
    else
        return max(res, query(x, i << 1 | 1, mid + 1, R));
}

signed main()
{
    fast;
    cin >> n;
    ll x1, x2;
    cin >> x1 >> x2;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        order[i] = i;
        r.emplace_back(i);
    }
    sort(r.begin(), r.end(), [&](ll i, ll j)
         { return c[i] < c[j]; });

    int cur = 0;
    for (int i = n - 1; i >= 1; i--)
        rmx[i] = max(rmx[i + 1], pll(c[r[i]] * (n - i), i));
    for (int k = n - 1; k >= 1; k--)
    {
        c[n + 1] = (x1 - 1) / k + 1;
        auto iter = lower_bound(r.begin(), r.end(), n + 1, [&](ll i, ll j)
                                { return c[i] < c[j]; });
        int idx = iter - r.begin();
        if (r.end() - iter < k)
            continue;
        for (; cur < idx; cur++)
        {
            modify(make_pair(pll(-c[r[cur]], (n - cur) * c[r[cur]]), cur));
        }

        pll lp = query(k);
        if (lp.F >= x2)
        {
            cout << "Yes\n";
            cout << k << " " << n - k - lp.S << '\n';

            for (int i = idx; i < idx + k; i++)
            {
                cout << r[i] << ' ';
                r[i] = -1;
            }
            cout << '\n';

            for (int i = lp.S; i < n; i++)
                if (r[i] > 0)
                    cout << r[i] << ' ';
            cout << '\n';
            return 0;
        }
        if (rmx[idx + k].F >= x2)
        {
            cout << "Yes\n";
            cout << k << " " << n - rmx[idx + k].S << '\n';
            for (int i = idx; i < idx + k; i++)
            {
                cout << r[i] << ' ';
                r[i] = -1;
            }
            cout << '\n';

            for (int i = rmx[idx + k].S; i < n; i++)
                cout << r[i] << ' ';
            cout << '\n';

            return 0;
        }
    }
    cout << "No\n";
}