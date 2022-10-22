#include <iostream>
using namespace std;

long long n, d, m, l, x;

int main()
{
    cin >> n >> d >> m >> l;
    for (long long i = 1; i <= n; i++) {
        if (x < (i - 1) * m) break;
        if (x > (i - 1) * m + l) continue;
        x += (((i - 1) * m + l - x) / d + 1) * d;
    }
    cout << x << endl;
    return 0;
}