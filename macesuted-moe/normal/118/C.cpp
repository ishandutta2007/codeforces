#include <bits/stdc++.h>
using namespace std;

int a[20005], vis[11], num[11];
char s[20005], anss[20005], str[20005];

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        num[s[i] - '0']++;
    int ans = 0x7fffffff;
    for (int i = 0; i <= 9; i++)
    {
        int tot = num[i], sum = 0;
        memcpy(str, s, sizeof(s));
        for (int j = 1; j <= 9 && tot < k; j++)
        {
            int x = i + j, y = i - j;
            if (x < 10)
                for (int l = 0; l < len && tot < k; l++)
                    if (str[l] - '0' == x)
                    {
                        str[l] = i + '0';
                        tot++;
                        sum += j;
                    }
            if (y >= 0)
                for (int l = len - 1; l >= 0 && tot < k; l--)
                    if (str[l] - '0' == y)
                    {
                        str[l] = i + '0';
                        tot++;
                        sum += j;
                    }
        }
        if (sum < ans)
        {
            ans = sum;
            strcpy(anss, str);
        }
        else if (sum == ans && strcmp(anss, str) > 0)
            strcpy(anss, str);
    }
    cout << ans << endl
         << anss;
    return 0;
}