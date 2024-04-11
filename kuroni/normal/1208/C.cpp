#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, cur = 0, tmp = 0, a[N][N];

void build(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            a[i][j] = cur++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 20; i >= 0; i--)
        if (n >> i & 1)
        {
            int st = (1 << i);
            for (int j = 0; j < tmp; j += st)
            {
                build(tmp, j, st);
                build(j, tmp, st);
            }
            build(tmp, tmp, st);
            tmp += st;
        }
    for (int i = 0; i < n; i++, cout << '\n')
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
}