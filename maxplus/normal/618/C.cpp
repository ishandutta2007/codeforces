#define first x
#define second y
#include <iostream>
#define in(p) cin >> p.x >> p.y

using namespace std;

typedef pair<int64_t, int64_t> point;

bool online(point a, point b, point c)
{
    b.x -= a.x;
    b.y -= a.y;
    c.x -= a.x;
    c.y -= a.y;
    return b.x * c.y - b.y * c.x == 0;
}

int64_t s(point a, point b, point c)
{
    b.x -= a.x;
    b.y -= a.y;
    c.x -= a.x;
    c.y -= a.y;
    return (b.x * c.y - b.y * c.x < 0? -(b.x * c.y - b.y * c.x): (b.x * c.y - b.y * c.x));
}

int64_t sqd(point a, point b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a.x * a.x + a.y * a.y;
}

point a[100001];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, num1 = 0, num2 = 1, num3 = 2;
    cin >> n;
    for (int i = 0; i < n; ++i)
        in(a[i]);
    for (int i = 1; i < n; ++i)
        if (sqd(a[num1], a[num2]) > sqd(a[num1], a[i]))
            num2 = i;
    for (int i = 0; i < n; ++i)
        if (!online(a[num1], a[num2], a[i]) && (s(a[num1], a[num2], a[num3]) > s(a[num1], a[num2], a[i]) || online(a[num1], a[num2], a[num3])))
            num3 = i;
    cout << num1 + 1 << ' ' << num2 + 1 << ' ' << num3 + 1;
    return 0;
}