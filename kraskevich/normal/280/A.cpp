#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const double eps = 1e-8;
const double pi = acos(-1);

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    double w, h, a;
    cin >> w >> h >> a;

    if (a > 90.0)
        a = 180.0 - a;

    cout.setf(ios::fixed);
    cout.precision(10);

    if (a < eps)
    {
        cout << w * h;
        return 0;
    }

    a /= 180.0;
    a *= pi;

    double f = (1 + cos(a)) / sin(a);
    double x = (h * f - w) / (f * f - 1);
    double y = h - x * f;

    if (x >= 0 && y >= 0 && y <= h + eps && x <= w + eps)
    {
        double ans = w * h;
        ans -=  x * x / tan(a);
        ans -= y * y / tan(a);
        cout << ans;
    }
    else
    {
        if (w < h)
            swap(w, h);
        cout << h * h / sin(a);
    }

    return 0;
}