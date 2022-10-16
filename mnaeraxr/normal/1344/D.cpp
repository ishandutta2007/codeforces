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

__int128_t get(__int128_t c, __int128_t top)
{
    // 0 <= 3 * t^2 - 3 * t + 1 + c

    auto pred = [&](__int128_t t) {
        return -3 * t * t + 3 * t - 1;
    };

    if (c <= pred(top))
        return top;

    __int128_t lo = 0,
               hi = top;

    while (lo + 1 < hi)
    {
        auto m = (lo + hi) / 2;

        if (c <= pred(m))
            lo = m;
        else
            hi = m;
    }

    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    vector<__int128_t> a(n);

    for (int i = 0; i < n; ++i)
    {
        long long u;
        cin >> u;
        a[i] = u;
    }

    __int128_t lo = -4000000000000000000LL, hi = 4000000000000000000LL;

    while (lo + 1 < hi)
    {
        auto m = (lo + hi) / 2;

        __int128_t cur = 0;

        for (auto x : a)
        {
            auto t = get(m - x, x);
            cur += t;
        }

        if (cur >= k)
            lo = m;
        else
            hi = m;
    }

    __int128_t total = 0;

    for (auto x : a)
    {
        auto t = get(lo - x, x);
        total += t;
    }
    assert(total >= k);
    total -= k;

    for (auto x : a)
    {
        auto t = get(lo - x, x);

        if (t && total && (3 * t * t - 3 * t + 1 - x == -lo))
        {
            total--;
            t--;
        }

        cout << (long long)t << " ";
    }

    cout << endl;

    return 0;
}