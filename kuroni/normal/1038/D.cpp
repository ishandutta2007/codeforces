#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 1E9 + 7;

int ma = -INF, mi = INF, n, a;
long long ans = 0;

int main()
{
    cin >> n;
    if (n == 1)
    {
        cin >> a;
        cout << a;
        return 0;
    }
    while (n--)
    {
        cin >> a;
        if (a > 0)
            ans += a;
        else
            ans -= a;
        ma = max(ma, a);
        mi = min(mi, a);
    }
    if (mi > 0)
        ans -= mi * 2;
    else if (ma < 0)
        ans += ma * 2;
    cout << ans;
}