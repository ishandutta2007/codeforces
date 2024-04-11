#include <iostream>
using namespace std;

char a[5005][5005];
int cnt[5005][5005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i] );
        int curp = m;
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i][j] == '0')
                curp = j;
            cnt[j][curp]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int ccnt = n;
        for (int j = i; j < m; j++)
        {
            ccnt -= cnt[i][j];
            ans = max(ans, ccnt * 1LL * (j - i + 1) );
        }
    }
    printf("%I64d", ans);

    return 0;
}