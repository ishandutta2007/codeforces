#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define For(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    static int ar[6] { 0, 5, 3, 2, 4, 1 };
    int x;
    cin >> x;
    int y = 0;
    For(i, 6)
        if ((x >> i) & 1)
            y |= 1 << (5 - ar[5 - i]);
    cout << y << '\n';
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