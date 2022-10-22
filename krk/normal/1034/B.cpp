#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    if (n > m) swap(n, m);
    ll res = 0;
    if (n == 1) {
        res = m / 6 * 6;
        m %= 6;
        if (m > 3) res += (m - 3) * 2;
    } else if (n == 2) {
        if (m == 3 || m == 7) res = n * m - 2;
        else if (m > 2) res = n * m;
    } else res = ll(n) * m / 2 * 2;
    printf("%I64d\n", res);
    return 0;
}