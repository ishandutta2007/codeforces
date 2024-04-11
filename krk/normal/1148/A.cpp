#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

int main()
{
    cin >> a >> b >> c;
    long long res = 2 * c + 2 * min(a, b);
    if (a > b) res++;
    if (b > 0) {
        long long res2 = 1 + 2 * c; b--;
        res2 += 2 * min(a, b);
        if (a > b) res2++;
        res = max(res, res2);
    }
    cout << res << endl;
    return 0;
}