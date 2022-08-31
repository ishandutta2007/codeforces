// CF_NERC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#define ll long long
#define maxn 5050
using namespace std;
int pre[maxn];
int a[maxn];
ll f[maxn/2][maxn/2];
ll C[maxn / 2][maxn / 2];
int n;
const int MOD = 998244353;
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i <= 2500; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
    for (int ii = 1; ii <= T; ++ii) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)scanf("%d", &a[i]);
        int m = n / 2;
        for (int i = 1; i <= m; ++i)swap(a[i], a[n - i + 1]);
        int m0 = 0;
        int m1 = 1;
        a[n + 1] = a[n] - 1;
        for (int i = n; i >= 1; --i) {
            if (a[i] == a[i + 1])pre[i] = pre[i + 1];
            else pre[i] = i + 1;
        }
        for (int i = 0; i <= m; ++i)for (int j = 0; j <= m; ++j)f[i][j] = 0;
        if (pre[1] == 2) f[1][0] = 1; else f[1][0] = 0;
        for (int i = 1; i <= m; ++i)for (int j = 0; j <= i; ++j) {
            if (i == m && j == m)break;
            if (f[i][j] == 0)continue;
            int x = i + j + 1;
            int y = pre[x] - x;
            if (i == m && j + y <= m) {
                f[i][j + y] += f[i][j] * C[i-j][y];
                f[i][j + y] %= MOD;
            }
            else if (i < m && j + y < i) {
                f[i][j + y] += f[i][j] * C[i-j-1][y];
                f[i][j + y] %= MOD;
            }

            if (i < m && j + y - 1 < i) {
                f[i + 1][j + y - 1] += f[i][j] * C[i - j - 1][y-1];
                f[i + 1][j + y - 1] %= MOD;
            }
        }
        printf("%d\n", f[m][m]);
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file