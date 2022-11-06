#include <iostream>
#define int long long
using namespace std;

const int M = 998244353;

int n, m, l, r, k;

int gp(int a, int b) {
    if (b == 1)
        return a % M;
    if (b % 2 == 0) {
        int x = gp(a, b / 2);
        return x * x % M;
    }
    return a * gp(a, b - 1) % M;
}

signed main()
{
    cin >> n >> m >> l >> r;
    k = r - l;
    int all = gp(k + 1, n * m);
    if (n * m % 2 == 1) {
        cout << all;
        return 0;
    }
    cout << (all + 1 - k % 2) * (M + 1) / 2 % M;
    return 0;
}