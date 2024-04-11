#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int M = 1e9 + 7;

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
        if (b % 2 == 1)
            b--, res *= a, res %= M;
        else
            b /= 2, a *= a, a %= M;
    return res;
}

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k == -1 && n % 2 != m % 2)
    {
        cout << 0;
        return 0;
    }
    cout << gp(gp(2, n - 1), m - 1);
    return 0;
}