#include <iostream>
#define N 301

using namespace std;

int n, p[N], pl[N], ans[N];
char a[N][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> p[i]), pl[--p[i]] = i;
    for (int i = 0; i < n; a[i][i] = '1', ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] |= a[i][k] & a[j][k];
    for (int i = 0; i < n; ++i)
        for (int pos = 0; pos < n; ++pos)
            if (a[pl[i]][pos] == '1' && !ans[pos])
            {
                ans[pos] = i + 1;
                break;
            }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    return 0;
}