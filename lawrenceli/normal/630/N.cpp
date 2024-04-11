#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < 0) a *= -1, b *= -1, c *= -1;
    int d = b * b - 4 * a * c;
    cout << fixed << setprecision(20) << ld(-b + sqrt(d)) / (2 * a) << '\n' << ld(-b - sqrt(d)) / (2 * a) << '\n';
}