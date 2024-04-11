#include <bits/stdc++.h>
using namespace std;

const int maxn = 105, maxlgn = 35;

long long f[maxn][maxlgn];

string a, b;
int n1, n2;

void work(void)
{
    int siza = a.size(), sizb = b.size();
    for (int i = 0; i < siza; i++)
    {
        int p = i;
        f[i][0] = 0;
        for (int j = 0; j < sizb; j++)
        {
            int cnt = 0;
            while (a[p] != b[j])
            {
                p = (p + 1) % siza;
                if (++cnt >= siza)
                {
                    cout << 0 << endl;
                    return;
                }
            }
            p = (p + 1) % siza;
            f[i][0] += cnt + 1;
        }
    }
    for (int j = 1; j <= 30; j++)
        for (int i = 0; i < siza; i++)
            f[i][j] = f[i][j - 1] + f[(i + f[i][j - 1]) % siza][j - 1];
    long long answer = 0;
    for (int start = 0; start < siza; start++)
    {
        long long p = start, ans = 0;
        for (int k = 30; ~k; k--)
            if (p + f[p % siza][k] <= siza * n1)
                p += f[p % siza][k], ans += 1 << k;
        answer = max(answer, ans);
    }
    cout << answer / n2 << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n1 >> n2 >> a >> b;
    work();
    return 0;
}