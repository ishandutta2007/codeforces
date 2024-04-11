#include <iostream>

using namespace std;

struct point{
    long long x, y;
};

struct line{
    long long a, b, c;
};

void getp(point &a)
{
    cin >> a.x >> a.y;
}

void getl(line &a)
{
    cin >> a.a >> a.b >> a.c;
}

line l;

long long f(point a)
{
    return a.x * l.a + a.y * l.b + l.c;
}

int main()
{
    point a, b;
    long long n, ans = 0;
    getp(a);
    getp(b);
    cin >> n;
    for (long long i = 0; i < n; ++i)
    {
        getl(l);
        if ((f(a) < 0) != (f(b) < 0))
            ans++;
    }
    cout << ans;
    return 0;
}