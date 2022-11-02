#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    int g = gcd(a, b);
    a /= g, b /= g;
    int k = min(n/a, m/b);
    int c = k*a, d = k*b;
    int lx = c, rx = 2*n-c, ly = d, ry = 2*m-d;
    int ax, ay;
    x *= 2, y *= 2;

    if (x < lx) ax = lx;
    else if (x > rx) ax = rx;
    else ax = x;

    if (y < ly) ay = ly;
    else if (y > ry) ay = ry;
    else ay = y;

    cout << (ax-c)/2 << ' ' << (ay-d)/2 << ' ' << (ax-c)/2+c << ' ' << (ay-d)/2+d << '\n';
}