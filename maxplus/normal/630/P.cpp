#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double n, r, al, pi = acos(-1);
    cin >> n >> r;
    al = pi / n;
    long double a = r / sin(pi - al * 1.5) * sin(al);
    cout.precision(30);
    cout << fixed;
    cout << a * r * sin(al / 2) * n;
    return 0;
}