/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
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

int N, Q, arr[200005];
const int B = 1000, C = 100;
pii qrange[200005];
pii qquery[200005];
struct block
{
    int L, R, lastQ = 1;
    vector<int> dsu, size, rank, rev;
    int idx;
    block() : L(1), R(1){};
    block(int L, int R) : L(L), R(R){};
    int find(int k)
    {
        return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
    }
    void init()
    {
        dsu.resize(C + 1);
        dsu.shrink_to_fit();
        size.resize(C + 1);
        size.shrink_to_fit();
        rank.resize(C + 1);
        rank.shrink_to_fit();
        rev.resize(C + 1);
        rev.shrink_to_fit();
        for (int i = 1; i <= C; i++)
        {
            dsu[i] = i;
            rank[i] = i;
            rev[i] = i;
            size[i] = 1;
        }
        idx = C;
    }
    void solve(int curQ)
    {
        for (; lastQ <= curQ; lastQ++)
            if (qrange[lastQ].F <= L && R <= qrange[lastQ].S)
                lazy(qquery[lastQ].F, qquery[lastQ].S);
        for (int i = L; i <= R; i++)
            arr[i] = rev[find(arr[i])];
        init();
    }
    void lazy(int x, int y)
    {
        // if x is not empty
        if (dsu[rank[x]] == rank[x])
        {
            // case 2: y is modified
            if (dsu[rank[y]] != rank[y])
            {
                idx++;
                dsu.emplace_back(idx);
                size.emplace_back(1);
                rank[y] = idx;
                rev.emplace_back(y);
            }
            // case 1: latest y isn't modified
            if (size[rank[x]] < size[rank[y]])
            {
                size[rank[y]] += size[rank[x]];
                dsu[rank[x]] = rank[y];
            }
            else
            {
                size[rank[x]] += size[rank[y]];
                dsu[rank[y]] = rank[x];
                swap(rank[x], rank[y]);
                rev[rank[x]] = x, rev[rank[y]] = y;
            }
        }
    }
};

block b[450];

signed main()
{
    //fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; (i - 1) * B + 1 <= N; i++)
    {
        b[i] = block((i - 1) * B + 1, min(i * B, N));
        b[i].init();
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        qrange[i] = {l, r};
        qquery[i] = {x, y};
        int ldx = (l + B - 1) / B, rdx = (r + B - 1) / B;
        if (ldx == rdx)
        {
            b[ldx].solve(i);
            for (int i = l; i <= r; i++)
                if (arr[i] == x)
                    arr[i] = y;
        }
        else
        {
            b[ldx].solve(i);
            for (int i = l; i <= ldx * B; i++)
                if (arr[i] == x)
                    arr[i] = y;
            b[rdx].solve(i);
            for (int i = (rdx - 1) * B + 1; i <= r; i++)
                if (arr[i] == x)
                    arr[i] = y;
        }
    }
    for (int i = 1; i <= (N + B - 1) / B; i++)
        b[i].solve(Q + 1);
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " \n"[i == N];
}