#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>

#define endl '\n'

using namespace std;

const int maxn = 20;
int arr[maxn];
int minv[maxn][maxn];
int maxv[maxn][maxn];

pair<int, int> calc(int b, int e)
{
    if (minv[b][e] != -1)
        return make_pair(minv[b][e], maxv[b][e]);

    if (b + 1 == e)
    {
        return make_pair(minv[b][e] = arr[b], maxv[b][e] = arr[b]);
    }

    int m = maxn, M = -1;

    for (int i = b + 1; i < e; ++i)
    {
        auto le = calc(b, i);
        auto ri = calc(i, e);

        if (le.first < ri.second)
        {
            m = min(m, le.first);
            M = max(M, ri.second);
        }
    }

    return make_pair(minv[b][e] = m, maxv[b][e] = M);
}

void solve()
{
    int n;
    cin >> n;

    bool ok = true;

    int f, l;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (i == 0)
            f = x;
        if (i + 1 == n)
            l = x;
    }

    cout << (f <= l ? "YES" : "NO") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int n = 5;
    // iota(arr, arr + n, 0);
    // do
    // {
    //     memset(minv, -1, sizeof minv);
    //     auto x = calc(0, n);
    //     // cout << x.first << " " << x.second << endl;
    //     if (x.second == -1)
    //     {
    //         int m = n + 1;
    //         bool ok = true;
    //         // for (int i = 0; i + 1 < n && ok; ++i)
    //         // {
    //         //     m = min(m, arr[i]);
    //         //     if (m == n - i - 1)
    //         //     {
    //         //         ok = false;
    //         //     }
    //         // }

    //         if (ok)
    //         {
    //             for (int i = 0; i < n; ++i)
    //                 cout << arr[i] << " ";
    //             cout << endl;
    //         }
    //     }
    // } while (next_permutation(arr, arr + n));

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}