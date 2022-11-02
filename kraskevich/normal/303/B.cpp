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

long long n, m, x, y, a, b;
long long ansx = -1, ansy = -1;
long long sx, sy, cx1, cx2, cy1, cy2;

long long sqr(long long a)
{
    return a * a;
}

long long dist(long long x1, long long y1, long long x2, long long y2)
{
    return sqr(x1 - x2) + sqr(y1 - y2);
}

void chk(long long xx, long long yy)
{
    if (xx < cx1 || xx > cx2)
        return;
    if (yy < cy1 || yy > cy2)
        return;
    if ((xx + sx) % 2 || (yy + sy) % 2)
        return;
    if (ansx == -1)
    {
        ansx = xx;
        ansy = yy;
        return;
    }
    long long ans = dist(ansx, ansy, x, y);
    long long cur = dist(xx, yy, x, y);
    if (cur < ans)
    {
        ansx = xx;
        ansy = yy;
        return;
    }
    if (cur > ans)
        return;
    if (xx < ansx || xx == ansx && yy < ansy)
    {
        ansx = xx;
        ansy = yy;
    }
}

void upd(long long x, long long y)
{
    for (long long i = x - 10; i <= x + 10; i++)
        for (long long j = y - 10; j <= y + 10; j++)
            chk(i, j);
}

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m >> x >> y >> a >> b;

    long long g = gcd(a, b);
    a /= g;
    b /= g;

    long long cnt1 = n / a;
    long long cnt2 = m / b;
    long long cnt = min(cnt1, cnt2);
    sx = cnt * a;
    sy = cnt * b;

    n *= 2;
    m *= 2;
    x *= 2;
    y *= 2;

    cx1 = sx;
    cy1 = sy;
    cx2 = n - sx;
    cy2 = m - sy;

    upd(cx1, cy1);
    upd(cx1, cy2);
    upd(cx2, cy1);
    upd(cx2, cy2);
    upd(cx1, y);
    upd(cx2, y);
    upd(x, cy1);
    upd(x, cy2);
    upd(x, y);

    long long x1 = ansx - sx;
    long long x2 = ansx + sx;
    long long y1 = ansy - sy;
    long long y2 = ansy + sy;
    x1 /= 2;
    y1 /= 2;
    x2 /= 2;
    y2 /= 2;

    cout << x1 << " " << y1 << " " << x2 << " " << y2;


    return 0;
}