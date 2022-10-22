#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld pi = acos(-1.0l);

int n, r;

int main()
{
    scanf("%d %d", &n, &r);
    ld a = 2 * pi / n;
    ld b = (pi - a) / 2;
    ld R = r * sin(a) / (2 * sin(b) - sin(a));
    cout << fixed << setprecision(8) << R << endl;
    return 0;
}