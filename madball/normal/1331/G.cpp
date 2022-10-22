#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

#define For(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int ar[11];
    For(i, 11)
        cin >> ar[i];
    cout << fixed << setprecision(2);
    for (int i = 10; i >= 0; --i)
    {
        double x = ar[i];
        double res = sqrt(abs(x)) + x * x * x * 5;
        if (res > 400)
            cout << "f(" << ar[i] << ") = MAGNA NIMIS!\n";
        else
            cout << "f(" << ar[i] << ") = " << sqrt(abs(x)) + x * x * x * 5 << '\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}