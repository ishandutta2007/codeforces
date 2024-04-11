#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

ld exp(ld b, int e) {
    if (!e) return 1;
    if (e & 1) return b * exp(b, e - 1);
    ld res = exp(b, e >> 1);
    return res * res;
}

int main() {
    int n, t;
    cin >> n >> t;
    cout << fixed << setprecision(20) << n * exp(1.000000011, t) << '\n';
}