#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define For(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int x;
    cin >> x;
    for (int i = 2; i <= x; ++i)
        if (x % i == 0)
        {
            cout << i << x / i << '\n';
            return;
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