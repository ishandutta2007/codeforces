#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long double ld;

const int maxn = 100100;

int n;
ld x[maxn], y[maxn];

ld dist(int i, int j) { return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); }

ld area(int i, int j) {
    return abs(x[0] * y[i] + x[i] * y[j] + x[j] * y[0] - y[0] * x[i] - y[i] * x[j] - y[j] * x[0]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int a = 1;
    ld dis = dist(0, a);
    for (int j = 2; j < n; j++)
        if (dist(0, j) < dis)
            a = j, dis = dist(0, j);

    int b;
    ld ar = 1e100;
    for (int j = 1; j < n; j++)
        if (j != a && area(a, j) < ar && area(a, j) > 0)
            b = j, ar = area(a, j);

    cout << "1 " << a + 1 << ' ' << b + 1 << '\n';
}