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

ll det(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}

// ->   ->
// ab x ac
int ori(pll a, pll b, pll c)
{
    ll d = det(b.F - a.F, b.S - a.S, c.F - a.F, c.S - a.S);
    if (d == 0)
        return 0;
    else
        return d < 0 ? -1 : 1;
}

double dis(pll a, pll b)
{
    return sqrt((b.F - a.F) * (b.F - a.F) + (b.S - a.S) * (b.S - a.S));
}

double deg(pll a, pll b, pll c)
{
    double d = (b.F - a.F) * (c.F - b.F) + (b.S - a.S) * (c.S - b.S);
    return d / dis(a, b) / dis(b, c);
}

// ->     ->
// ab and ac
bool concave(pll a, pll b, pll c)
{
    int o = ori(a, b, c);
    if (o < 0 || (o == 0 && (b.F - a.F) * (c.F - a.F) + (b.S - a.S) * (c.S - a.S) <= 0))
        return true;
    return false;
}

vector<pll> convex(vector<pll> p)
{
    sort(p.begin(), p.end());
    vector<pll> hull;
    for (auto point : p)
    {
        while (hull.size() >= 2 && concave(hull[hull.size() - 1], hull[hull.size() - 2], point))
            hull.pop_back();
        hull.push_back(point);
    }
    reverse(p.begin(), p.end());
    for (auto point : p)
    {
        while (hull.size() >= 2 && concave(hull[hull.size() - 1], hull[hull.size() - 2], point))
            hull.pop_back();
        hull.push_back(point);
    }
    hull.pop_back();
    return hull;
}

vector<int> GetSA(deque<double> original)
{
    vector<double> s(original.begin(), original.end());
    vector<int> v;
    int N = s.size();
    vector<int> sa(N), tmp(N);
    for (int i = 0; i < N; i++)
        v.emplace_back(i);
    sort(v.begin(), v.end(), [&](int i, int j)
         { return make_pair(s[i], i) < make_pair(s[j], j); });
    sa[0] = 0;
    for (int i = 1; i < N; i++)
        sa[v[i]] = sa[v[i - 1]] + (s[v[i]] != s[v[i - 1]]);
    for (int k = 1; k <= N; k *= 2)
    {
        vector<int> count(N + 1), u(N);
        for (int i = 0; i < N; i++)
            v[i] = (v[i] - k + N) % N;
        for (int i = 0; i < N; i++)
            count[sa[v[i]] + 1]++;
        for (int i = 1; i <= N; i++)
            count[i] += count[i - 1];
        for (int i = 0; i < N; i++)
            u[count[sa[v[i]]]++] = v[i];
        v.swap(u);

        tmp[0] = 0;
        for (int i = 1; i < N; i++)
            tmp[v[i]] = tmp[v[i - 1]] + (make_pair(sa[v[i]], sa[(v[i] + k) % N]) != make_pair(sa[v[i - 1]], sa[(v[i - 1] + k) % N]));
        sa.swap(tmp);
    }
    return sa;
}

signed main()
{
    fast;
    int n, m;
    cin >> n >> m;
    vector<pll> a(n), b(m);
    cin >> a >> b;
    a = convex(a), b = convex(b);
    if (a.size() != b.size())
    {
        cout << "NO\n";
        return 0;
    }
    // for (auto [x, y] : a)
    //     printf("(%d, %d) ", x, y);
    // cout << '\n';
    // for (auto [x, y] : b)
    //     printf("(%d, %d) ", x, y);
    // cout << '\n';
    int A = a.size(), B = b.size();
    deque<double> va, vb;
    for (int i = 0; i < A; i++)
    {
        va.push_back(dis(a[i], a[(i + 1) % A]));
        va.push_back(deg(a[i], a[(i + 1) % A], a[(i + 2) % A]));
    }
    for (int i = 0; i < B; i++)
    {
        vb.push_back(dis(b[i], b[(i + 1) % B]));
        vb.push_back(deg(b[i], b[(i + 1) % B], b[(i + 2) % B]));
    }
    vector<int> sA = GetSA(va), sB = GetSA(vb);
    for (int i = 0; i < sA.size(); i++)
        if (sA[i] == 0)
        {
            for (int j = 0; j < i; j++)
            {
                va.push_back(va.front());
                va.pop_front();
            }
            break;
        }
    for (int i = 0; i < sB.size(); i++)
        if (sB[i] == 0)
        {
            for (int j = 0; j < i; j++)
            {
                vb.push_back(vb.front());
                vb.pop_front();
            }
            break;
        }
    bool same = 1;
    for (int i = 0; i < sA.size(); i++)
        if (abs(va[i] - vb[i]) > 1e-9)
            same = 0;
    cout << (same ? "YES" : "NO");
}