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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> res;
    vector<int> freq(n + 1);
    int last = 0;

    auto mex = [&]() {
        last++;
        for (auto x : a)
        {
            if (x < freq.size())
                freq[x] = last;
        }

        int r = 0;
        while (freq[r] == last)
            ++r;
        return r;
    };

    while (!is_sorted(a.begin(), a.end()))
    {
        int m = mex();

        if (m == n)
        {
            int p = 0;
            while (a[p] == p)
                ++p;
            int q = 0;
            while (a[q] != p)
                ++q;
            a[q] = m;
            res.push_back(q + 1);
        }
        else
        {
            a[m] = m;
            res.push_back(m + 1);
        }
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    // for (auto u : a)
    //     cout << u << " ";
    // cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}