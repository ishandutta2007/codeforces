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

int n, a, b;
vector<int> E[100005];
int pre[100005], branch[100005];
vector<pii> dep[100005];
bool ans = 0, able[100005];
int len = 0;

void dfs(int k)
{
    for (int i = 0; i < 3; i++)
        dep[k].emplace_back(pii(0, 0));
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs(i);
            dep[k].emplace_back(pii(dep[i][0].F + 1, i));
        }
    sort(dep[k].begin(), dep[k].end(), greater<>());
    dep[k].resize(3);
}

void chroot(int k)
{
    if (dep[k][2].F >= len)
        able[k] = 1;
    
    for (int i : E[k])
        if (i != pre[k])
        {
            for (auto [d, child] : dep[k])
                if (child != i)
                {
                    dep[i].emplace_back(pii(d + 1, k));
                    break;
                }
            sort(dep[i].begin(), dep[i].end(), greater<>());
            dep[i].resize(3);
            chroot(i);
        }
}

bool cald(int k)
{
    branch[k] = 0;
    bool hasb = (k == b);
    for (int i : E[k])
        if (i != pre[k])
        {
            if (cald(i))
                hasb = 1;
            else
                branch[k] = max(branch[k], branch[i] + 1);
        }
    return hasb;
}

void solve()
{
    ans = len = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        E[i].clear();
    for (int i = 1; i <= n; i++)
    {
        pre[i] = 0;
        dep[i].clear();
    }
    cin >> a >> b;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        able[i] = 0;

    dfs(a);
    deque<int> path;
    int c = b;
    while (c != a)
    {
        path.emplace_back(c);
        c = pre[c], len++;
    }
    path.emplace_back(a);
    reverse(path.begin(), path.end());
    chroot(a);
    cald(a);
    int l = 0, r = len, L = branch[path.back()], R = len - branch[path.front()];
    while (!path.empty())
    {
        //cout << l << " " << L << " " << R << " " << r << '\n';
        R = min(R, len - branch[path.front()] + l);
        L = max(L, branch[path.back()] - (len - r));
        if (l < L)
        {
            l++;
            path.pop_front();
        }
        else if (r > R)
        {
            r--;
            path.pop_back();
        }
        else
            break;
    }
    for (int i = 1; i <= n; i++)
        ans |= able[i];
    if (ans && path.size() <= 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}