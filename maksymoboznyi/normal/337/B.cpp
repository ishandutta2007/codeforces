#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 100;

double a, b, c, d;
int p, q;
int main()
{
    cin >> a >> b >> c >> d;
    double ans = 0;
    q = 1;
    if (a * d / c <= b && a * d >= ans)
        ans = a * d, p = b*c-a*d, q = b*c;
    if (b * c / d <= a && b * c >= ans)
        ans = b * c, p = a * d - b * c, q = a*d;
    int x = __gcd(p, q);
    p /= x;
    q /= x;
    cout << p << '/' << q;
    return 0;
}