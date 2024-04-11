#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

constexpr int N = 1000;

int n, r;
long double x[N], y[N];

int main()
{
    cin >> n >> r;
    cout << fixed;
    cout.precision(30);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i] = r;
        for (int j = 0; j < i; ++j) if (abs(x[j] - x[i]) <= 2 * r)
            y[i] = max(y[i], y[j] + sqrtl(4 * r * r - (x[j] - x[i]) * (x[j] - x[i])));
        cout << y[i] << '\n';
    }
    return 0;
}