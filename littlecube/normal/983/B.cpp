#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int n, a[5000], r[5000][5000], q;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        r[0][i] = a[i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            r[i][j] = r[i - 1][j] ^ r[i - 1][j + 1];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            r[i][j] = max(max(r[i - 1][j], r[i - 1][j + 1]), r[i][j]);

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << r[b - a][a - 1] << '\n';
    }
}