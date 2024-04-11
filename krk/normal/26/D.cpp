#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

int n, m, k;
ld ans;

int main()
{
    cin >> n >> m >> k;
    ans = 1;
    if (k + n - m < 0) { cout << "0\n"; return 0; }
    for (int i = 0; i <= k; i++) {
        ans *= m - i;
        ans /= n + 1 + i;
    }
    cout << fixed << setprecision(6) << 1 - ans << endl;
    return 0;
}