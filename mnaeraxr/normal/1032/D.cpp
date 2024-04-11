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

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;

void solve()
{
    double a, b, c;
    double x0, y0, x1, y1;
    cin >> a >> b >> c >> x0 >> y0 >> x1 >> y1;

    if (abs(a) < 0.5 || abs(b) < 0.5)
    {
        cout << abs(x0 - x1) + abs(y0 - y1) << endl;
        return;
    }

    double res = abs(x0 - x1) + abs(y0 - y1);

    complex<double> i0(x0, y0);
    complex<double> p00(x0, (-c - a * x0) / b);
    complex<double> p01((-c - b * y0) / a, y0);

    complex<double> i1(x1, y1);
    complex<double> p10(x1, (-c - a * x1) / b);
    complex<double> p11((-c - b * y1) / a, y1);

    for (auto p0 : {p00, p01})
    {
        for (auto p1 : {p10, p11})
        {
            double cur = abs(i0 - p0) + abs(p0 - p1) + abs(p1 - i1);
            
            res = min(res, cur);
        }
    }

    cout << res << endl;
}

int main()
{
    cout.precision(12);
    cout << fixed;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}