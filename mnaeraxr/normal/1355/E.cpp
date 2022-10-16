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

#define endl '\n'

using namespace std;

long long solve(vector<long long> h, int n, long long s, long long a, long long r, long long m)
{
    sort(h.begin(), h.end());

    m = min(m, a + r);

    long long res = r * s, p = 0;

    for (int i = 0; i < n; ++i)
    {
        s -= h[i];

        long long ta = h[i] * i - p;
        long long tb = s - h[i] * (n - i - 1);
        auto tm = min(ta, tb);

        ta -= tm;
        tb -= tm;

        long long cost = m * tm + a * ta + r * tb;

        res = min(res, cost);

        p += h[i];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long a, r, m;
    cin >> n >> a >> r >> m;

    vector<long long> h(n);

    long long s = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
        s += h[i];
    }

    auto res = solve(h, n, s, a, r, m);

    h.push_back(s / n);
    res = min(res, solve(h, n + 1, s + s / n, a, r, m));
    h.pop_back();
    h.push_back((s + n - 1) / n);
    res = min(res, solve(h, n + 1, s + (s + n - 1) / n, a, r, m));

    cout << res << endl;

    return 0;
}