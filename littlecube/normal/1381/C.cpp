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

int b[100005], ans[100005];
vector<int> pos[100005];

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n + 1; i++)
        pos[i].clear();

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        pos[b[i]].emplace_back(i);
    }

    int spare = 0;
    for (int i = 1; i <= n + 1; i++)
        if (pos[i].size() == 0)
            spare = i;
    priority_queue<pii> pq;
    for (int i = 1; i <= n + 1; i++)
        pq.push(pii(pos[i].size(), i));

    for (int i = 1; i <= x; i++)
    {
        auto [cnt, id] = pq.top();
        pq.pop();
        ans[pos[id].back()] = id;
        pos[id].pop_back();
        pq.push(pii(cnt - 1, id));
    }
    vector<int> rem;
    for (int i = 1; i <= n - y; i++)
    {
        auto [cnt, id] = pq.top();
        pq.pop();
        ans[pos[id].back()] = spare;
        pos[id].pop_back();
        rem.emplace_back(id);
        pq.push(pii(cnt - 1, id));
    }
    while (!pq.empty())
        pq.pop();

    int left = y - x;

    for (int i = 1; i <= n + 1; i++)
    {
        if ((int)pos[i].size() - (y - x) / 2 == 1 && !rem.empty() && rem.back() != i)
        {
            ans[pos[i].back()] = rem.back();
            rem.pop_back();
            pos[i].pop_back();
            left--;
        }
        if (pos[i].size() > (y - x) / 2)
        {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 1; i <= n + 1; i++)
        pq.push(pii(pos[i].size(), i));
    while (left > 0 && left != 3)
    {
        auto [cnt1, id1] = pq.top();
        pq.pop();
        auto [cnt2, id2] = pq.top();
        pq.pop();
        ans[pos[id1].back()] = id2;
        ans[pos[id2].back()] = id1;
        pos[id1].pop_back();
        pos[id2].pop_back();
        pq.push(pii(cnt1 - 1, id1));
        pq.push(pii(cnt2 - 1, id2));
        left -= 2;
    }
    if (left == 3)
    {
        auto [cnt1, id1] = pq.top();
        pq.pop();
        auto [cnt2, id2] = pq.top();
        pq.pop();
        auto [cnt3, id3] = pq.top();
        pq.pop();
        ans[pos[id1].back()] = id2;
        ans[pos[id2].back()] = id3;
        ans[pos[id3].back()] = id1;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}