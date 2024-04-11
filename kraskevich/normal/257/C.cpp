#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <ctime>
#include <ctype.h>

using namespace std;


const int N = 100 * 1000 + 10;
const double pi = acos(-1);
double angle[N];

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        angle[i] = atan2(y, x);
        if (angle[i] < 0)
            angle[i] += 2 * pi;
    }

    sort(angle, angle + n);
    angle[n] = angle[0] + 2 * pi;

    double mx = 0;
    for (int i = 0; i < n; ++i)
        mx = max(mx, angle[i + 1] - angle[i]);

    double res = 2 * pi - mx;
    res /= pi;
    res *= 180.0;

    cout.setf(ios::fixed);
    cout.precision(10);

    cout << res;

    return 0;
}