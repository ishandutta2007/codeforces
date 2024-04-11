#include <iostream>
using namespace std;

int main() {
    long long n, l, k, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    long long x = k * l / (n * nl), y = (c * d) / n, z = p / (n * np);
    cout << min(min(x, y), z);
    cin >> c;
    return 0;
}