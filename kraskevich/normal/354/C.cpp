#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000 + 10;

int f[N];
int sum[N];
int a[N];
int n;
int k;
int res = 1;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    fill(sum, sum + N, 0);
    fill(f, f + N, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + f[i];
    for (int d = 2; d <= 1000 * 1000; d++)
    {
        int was = 0;
        int add = min(k, d - 1);
        for (int x = d; x < N; x += d)
        {
            int to = min(N - 1, x + add);
            was += sum[to] - sum[x - 1];
        }
        if (was == n)
            res = d;
    }

    cout << res;

    return 0;
}