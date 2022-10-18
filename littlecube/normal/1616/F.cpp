/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
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

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, idx = 0, a[5000][270] = {{}}, adj[70][70] = {{}}, x[270] = {}, b[5000] = {};
        // a1x1 + a2x2 + ... = b
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v >> x[i];
            adj[u][v] = adj[v][u] = i;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int k = j + 1; k <= n; k++)
                    if (adj[i][j] && adj[j][k] && adj[k][i])
                    {
                        int p = adj[i][j], q = adj[j][k], r = adj[k][i];
                        idx++;
                        if (x[p] == -1)
                            a[idx][p] = 1;
                        else
                            b[idx] = (b[idx] - x[p] + 3) % 3;
                        if (x[q] == -1)
                            a[idx][q] = 1;
                        else
                            b[idx] = (b[idx] - x[q] + 3) % 3;
                        if (x[r] == -1)
                            a[idx][r] = 1;
                        else
                            b[idx] = (b[idx] - x[r] + 3) % 3;
                    }
        /*
        for (int i = 1; i <= idx; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << a[i][j] << " ";
            cout << "= " << b[i] << '\n';
        }
        for (int i = 1; i <= m; i++)
            cout << x[i] << " \n"[i == m];
            */
        int solved = 0;
        for (int i = 1; i <= m; i++)
        {
            int j = i + solved;
            if (j > idx)
                break;

            if (!a[j][i])
            {
                for (int k = j + 1; k <= idx; k++)
                    if (a[k][i])
                    {
                        for (int l = 1; l <= m; l++)
                            swap(a[j][l], a[k][l]);
                        swap(b[j], b[k]);
                        break;
                    }
            }
            if (a[j][i])
            {
                for (int k = j + 1; k <= idx; k++)
                    if (a[k][i])
                    {
                        //cout << j << " elimiate " << k << '\n';
                        int mul = a[k][i];
                        for (int l = 1; l <= m; l++)
                        {
                            a[k][l] = ((a[k][l] * a[j][i] - a[j][l] * mul) + 33333) % 3;
                            assert(a[k][l] >= 0);
                        }
                        b[k] = ((b[k] * a[j][i] - b[j] * mul) + 33333) % 3;
                        assert(b[k] >= 0);
                    }
            }
            else
                solved--;
            /*
            for (int i = 1; i <= idx; i++)
            {
                for (int j = 1; j <= m; j++)
                    cout << a[i][j] << " ";
                cout << "= " << b[i] << '\n';
            }
            cout << '\n';
            */
        }
        bool valid = true;
        int cur = m;
        for (int i = idx; i >= 1; i--)
        {
            int nonzero = 0;
            for (int j = 1; j <= m; j++)
            {
                if (nonzero == 0 && a[i][j] != 0)
                {
                    nonzero = j;
                    for (int k = nonzero + 1; k <= cur; k++)
                        if (x[k] == -1)
                            x[k] = 3;
                    cur = j;
                }
                else if (a[i][j] != 0)
                {
                    b[i] = (b[i] - a[i][j] * x[j] + 33333) % 3;
                    assert(b[i] >= 0);
                    a[i][j] = 0;
                }
            }
            if (nonzero == 0 && b[i] != 0)
            {
                valid = false;
                break;
            }
            else if (nonzero != 0)
            {
                x[nonzero] = (b[i] * a[i][nonzero] + 33333) % 3;
                // should be b[i] / a[i][nonzero] but 1 * 1 = 1 (mod 3) and 2 * 2 = 1 (mod 3)
                assert(x[nonzero] >= 0);
            }
            /*
            for (int i = 1; i <= m; i++)
                cout << x[i] << " \n"[i == m];
            */
        }
        for (int j = 1; j <= m; j++)
            if (x[j] == -1)
                x[j] = 3;
        if (valid)
            for (int i = 1; i <= m; i++)
                cout << (x[i] == 0 ? 3 : x[i]) << " \n"[i == m];
        else
            cout << "-1\n";
    }
}
/*
1
4 6
1 2 3
1 3 -1
1 4 -1
2 3 -1
2 4 -1
3 4 -1

1
5 10
1 2 1
1 3 -1
1 4 -1
1 5 -1
2 3 -1
2 4 -1
2 5 -1
3 4 -1
3 5 -1
4 5 -1
*/