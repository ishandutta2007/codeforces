#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

const ld PI = acos(-1.0);

int main() {
    ld a, b, c;
    cin >> a >> b >> c;
    ld ans = 0;
    ans += a * a * a * sqrt(2) / 12;
    ans += b * b * b / sqrt(2) / 3;
    ld d = c / tan(36 * PI / 180) / 2;
    ans += sqrt(c * c * 3 / 4 - d * d) * 5 * c * d / 6;
    cout << fixed << setprecision(10) << ans << '\n';
}