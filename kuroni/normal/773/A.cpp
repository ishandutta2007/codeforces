#include <iostream>
#include <stdio.h>
using namespace std;

int x, y, p, q, t, i;

long long solve()
{
    long long niitan = max((y - 1) / q + 1, (x - 1) / p + 1);
    if (p * niitan - x > q * niitan - y) niitan = (y - x - 1) / (q - p) + 1;
    return q * niitan - y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cin >> x >> y >> p >> q;
        if (p == 0 && x == 0) cout << 0 << '\n';
        else if (p == 0 && x != 0) cout << -1 << '\n';
        else if (p == 1 && q == 1 && x != y) cout << -1 << '\n';
        else if (q * x - p * y == 0) cout << 0 << '\n';
        else cout << solve() << '\n';
    }
	return 0;
}