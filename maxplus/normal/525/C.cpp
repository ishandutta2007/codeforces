#include <iostream>
#define N 1000000

using namespace std;

int am[N + 2], am1[N + 2];

int main()
{
    int n, a;
    int64_t pl = N + 1, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> a), am[a]++;
    for (int64_t l = N; l > 0; --l)
    {
        if (((am1[l] + am[l]) & 1) && am[l] > 0)
            --am[l], ++am1[l - 1];
        while ((am[pl] + am1[pl]) > 1 && (am[l] + am1[l]) > 1)
            ans += pl * l, ----am1[pl], ----am1[l];
        while ((am[l] + am1[l]) > 3)
            ans += l * l, --------am1[l];
        if (am[l] + am1[l] > 1)
            pl = l;
    }
    cout << ans;
    return 0;
}