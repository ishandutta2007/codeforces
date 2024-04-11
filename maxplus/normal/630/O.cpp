#include <iostream>
#include <cmath>

using namespace std;

struct point{
    long double x, y;
    static point p(long double x, long double y)
    {
        point a;
        a.x = x, a.y = y;
        return a;
    }
    point& operator +=(point b)
    {
        x += b.x, y += b.y;
        return *this;
    }
    point operator +(point b)
    {
        point a = *this;
        return a += b;
    }
    point& operator -=(point b)
    {
        x -= b.x, y -= b.y;
        return *this;
    }
    point operator -(point b)
    {
        point a = *this;
        return a -= b;
    }
    point operator *(long double b)
    {
        return p(x * b, y * b);
    }
    point operator /(long double b)
    {
        return p(x / b, y / b);
    }
    long double len()
    {
        return hypotl(x, y);
    }
};

point mp(long double x, long double y)
{
    point a;
    a.x = x, a.y = y;
    return a;
}

ostream &operator <<(ostream &out, point x)
{
    out << x.x << ' ' << x.y << '\n';
    return out;
}

int main()
{
    point p, v, rv;
    int a, b, c, d;
    cin >> p.x >> p.y >> v.x >> v.y >> a >> b >> c >> d;
    rv = mp(-v.y, v.x);
    cout.precision(30);
    cout << fixed;
    cout << p + v / v.len() * b;
    cout << p + rv / v.len() * a / 2;
    cout << p + rv / v.len() * c / 2;
    cout << p + rv / v.len() * c / 2 - v / v.len() * d;
    cout << p - rv / v.len() * c / 2 - v / v.len() * d;
    cout << p - rv / v.len() * c / 2;
    cout << p - rv / v.len() * a / 2;
    return 0;
}