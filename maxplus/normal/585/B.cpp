#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n, t, k, f, a[3][105], pos[3][105];

bool ans(int a, int b)
{
    if (a > 2 || a < 0)
        return 0;
    if (b >= n)
        return 1;
    if (!::a[a][b])
        return 0;
    if (pos[a][b] != -1)
        return pos[a][b];
    return pos[a][b] = ::a[a][b + 1] && ::a[a][b + 2] && ::a[a][b + 3] && (ans(a - 1, b + 3) || ans(a, b + 3) || ans(a + 1, b + 3));
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(pos, 255, sizeof(pos));
        for (int k = 0; getchar(), k < 3; ++k)
        for (int i = 0; i < n; ++i) if (cin.peek() == 's') getchar(), f = k, a[k][i] = 1; else
            a[k][i] = getchar() == '.';
        for (int k = 0; k <= 2; ++k)
        for (int i = n; i < n + 3; ++i)
            a[k][i] = 1;
        cout << ((a[f][1] && (ans(f - 1, 1) || ans(f, 1) || ans(f + 1, 1)))? "YES\n":"NO\n");
    }
    return 0;
}