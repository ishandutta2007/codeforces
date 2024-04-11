#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;

long long n, x, y, c;

long long ABS(long long a)
{
    return a > 0 ? a : -a;
}

long long getSum(long long start, long long cnt)
{
    if (cnt <= 0)
        return 0;
    return (2ll * start + cnt - 1ll) * cnt / 2ll;
}

long long calc(long long dx, long long dy, long long timer)
{
    long long res = dx * dy;
    long long highX = timer + 1;
    long long highY = timer + 1;
    long long start;

    if (highX >= dx)
        start = 1;
    else
        start = dx - highX;

    long long rect;
    if (highY >= dy)
        rect = 0;
    else
        rect = dy - highY;

    long long beginY;
    if (highX < dx)
        beginY = 0;
    else
        beginY = highX - dx + 1;

    long long finY = dy - rect;

    return dx * dy - rect * dx - getSum(start, finY - beginY);
}

bool check(long long timer)
{
    long long sum = 0;
    long long dx, dy;

    dx = ABS(x);
    dy = ABS(y);
    sum += calc(dx, dy, timer);

    dx = ABS(n - x + 1);
    dy = ABS(n - y + 1);
    sum += calc(dx, dy, timer);

    dx = ABS(x);
    dy = ABS(n - y + 1);
    sum += calc(dx, dy, timer);

    dx = ABS(n - x + 1);
    dy = ABS(y);
    sum += calc(dx, dy, timer);

    sum -= min(timer + 1, ABS(y));
    sum -= min(timer + 1, ABS(x));
    sum -= min(timer + 1, ABS(n - x + 1));
    sum -= min(timer + 1, ABS(n - y + 1));
    sum++;

    return sum >= c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> x >> y >> c;

    long long low = 0, high = 1000 * 1000 * 1000 * 2;

    while (low < high)
    {
        long long middle = (low + high) / 2ll;
        if (check(middle))
            high = middle;
        else
            low = middle + 1;
    }

    cout << low;

    return 0;
}