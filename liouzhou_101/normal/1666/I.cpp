#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template<class T>
bool freshmax(T& a, const T& b)
{
    return a < b ? a = b, 1 : 0;
}

template<class T>
bool freshmin(T& a, const T& b)
{
    return a > b ? a = b, 1 : 0;
}

typedef int i32;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
typedef double f64;
typedef long double f80;

using ll = long long;

constexpr ll INF = 10000000000000000LL;

#ifdef ONLINE_JUDGE
constexpr static int oj = 1;
#else
constexpr static int oj = 0;
#endif

#define debug if constexpr (!oj)

int N = 15;
int M = 11;
int X1 = 3, Y1 = 6;
int X2 = 8, Y2 = 10;

int dig(int x, int y)
{
    cout << "DIG " << x << " " << y << endl;
    if (oj)
    {
        int z;
        cin >> z;
        return z;
    }
    else
    {
        return (x == X1 && y == Y1) || (x == X2 && y == Y2);
    }
}

int scan(int x, int y)
{
    cout << "SCAN " << x << " " << y << endl;
    if (oj)
    {
        int z;
        cin >> z;
        return z;
    }
    else
    {
        return abs(x - X1) + abs(x - X2) + abs(y - Y1) + abs(y - Y2);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int s11 = scan(1, 1);
    // s11 = x1+x2-2+y1+y2-2
    int s1m = scan(1, m);
    // s1m = x1+x2-2+2*m-y1-y2
    assert((s11 + s1m - 2 * m + 2) % 2 == 0);
    int sx = (s11 + s1m - 2 * m + 2) / 2 + 2;
    // sx = x1+x2
    assert((s11 - s1m + 2 * m + 2) % 2 == 0);
    int sy = (s11 - s1m + 2 * m + 2) / 2;
    // sy = y1+y2
    int mx = sx / 2;
    int my = sy / 2;

    int smx1 = scan(mx, 1);
    int dx = smx1 - sy + 2;
    // dx = x2-x1
    assert((sx + dx) % 2 == 0);
    int x2 = (sx + dx) / 2;
    int x1 = (sx - dx) / 2;

    int s1my = scan(1, my);
    int dy = s1my - sx + 2;
    // dy = y2-y1
    assert((sy + dy) % 2 == 0);
    int y2 = (sy + dy) / 2;
    int y1 = (sy - dy) / 2;

    if (dig(x1, y1))
    {
        dig(x2, y2);
    }
    else
    {
        dig(x1, y2);
        dig(x2, y1);
    }
}

int main()
{
    int tests;
    cin >> tests;
    while (tests--) solve();
    return 0;
}