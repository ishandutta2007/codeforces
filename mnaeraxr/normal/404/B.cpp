#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

#include <experimental/optional>

#include <random>

#include <utility>

#define endl '\n'

using namespace std;

void solve()
{
    double a, d;
    cin >> a >> d;

    int lo = 0, hi = 1;

    while (4 * a * hi + 1e-9 <= d)
        hi *= 2;
    while (lo + 1 < hi)
    {
        int m = (lo + hi) / 2;
        if (4 * a * m + 1e-9 <= d)
            lo = m;
        else
            hi = m;
    }

    d -= 4 * a * lo;
    assert(d >= 0);

    int n;
    cin >> n;

    double x = 0, y = 0;
    int section = 0;

    cout.precision(10);
    cout << fixed;

    for (int i = 0; i < n; ++i)
    {
        double rem = d;

        while (rem > 1e-7)
        {
            double t;
            if (section == 0)
            {
                t = a - x;
            }
            else if (section == 1)
            {
                t = a - y;
            }
            else if (section == 2)
            {
                t = x;
            }
            else
            {
                t = y;
            }

            t = min(t, rem);

            rem -= t;

            if (section == 0)
            {
                x += t;
            }
            else if (section == 1)
            {
                y += t;
            }
            else if (section == 2)
            {
                x -= t;
            }
            else
            {
                y -= t;
            }

            if (rem > 1e-9)
                section = (section + 1) & 3;
        }

        cout << x << " " << y << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}