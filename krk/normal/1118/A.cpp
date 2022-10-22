#include <bits/stdc++.h>
using namespace std;

int q;
long long n, a, b;

int main()
{
    scanf("%d", &q);
    while (q--) {
        long long res = 0;
        cin >> n >> a >> b;
        b = min(b, 2 * a);
        res = n / 2 * b;
        if (n % 2) res += a;
        cout << res << endl;
    }
    return 0;
}