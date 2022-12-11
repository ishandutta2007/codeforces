/**
 *    author:  tourist
 *    created: 16.08.2022 17:54:45
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> ds;
        int old = n;
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                ds.push_back(old / i);
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        n = old;
        int sz = (int)ds.size();
        vector<vector<long long>> b(sz);
        for (int i = 0; i < sz; i++)
        {
            b[i].resize(ds[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                b[j][i % ds[j]] += a[i];
            }
        }
        multiset<long long> s;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < ds[i]; j++)
            {
                s.insert(b[i][j] * ds[i]);
            }
        }
        cout << (*s.rbegin()) << '\n';
        while (q--)
        {
            int pos, val;
            cin >> pos >> val;
            --pos;
            int delta = val - a[pos];
            a[pos] = val;
            for (int i = 0; i < sz; i++)
            {
                int j = pos % ds[i];
                s.erase(s.find(b[i][j] * ds[i]));
                b[i][j] += delta;
                s.insert(b[i][j] * ds[i]);
            }
            cout << (*s.rbegin()) << '\n';
        }
    }
    return 0;
}