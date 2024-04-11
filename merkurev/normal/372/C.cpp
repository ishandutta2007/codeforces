#include <iostream>
using namespace std;

int a[305], b[305], tm[305];
int ans[2][300500];
const int inf = 1e9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = n; i < 300500; i++)
        ans[0][i] = ans[1][i] = inf;
    long long sum = 0;
    int prevt = 0;
    for (int i = 0; i < m; i++)
    {
        int t = (i & 1);
        int nt = (t ^ 1);

        scanf("%d%d%d", &a[i], &b[i], &tm[i] );
        a[i]--;
        sum += b[i];
        int pos = a[i];
        long long XX = d * 1LL * (tm[i] - prevt);
        int D = min(XX, long long(n - 1) );
        prevt = tm[i];
        int mn = inf;
        int YY = min(n - 1 + D, 2 * D);
        for (int j = 0; j <= YY; j++)
        {
            if (ans[t][j] < mn)
                mn = ans[t][j];
            if (j >= D)
                ans[nt][j - D] = mn;
        }
        int up = n - D - 1;
        for (int j = 0; j < up; j++)
        {
            mn = min(ans[t][j + 2 * D + 1], mn);
            if (ans[t][j] == mn)
                mn = ans[t][j + 1];
            ans[nt][j + D + 1] = mn;
        }

        for (int j = 0; j <= pos; j++)
            ans[nt][j] += pos - j;
        for (int j = pos + 1; j < n; j++)
            ans[nt][j] += j - pos;
    }
    int t = (m & 1);
    int answer = inf;
    for (int i = 0; i < n; i++)
        answer = min(answer, ans[t][i] );

    printf("%I64d", sum - answer);



    return 0;
}