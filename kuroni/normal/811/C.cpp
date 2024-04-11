#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, a[5005], i, j, cnt = 0, cnt_a[5005], tmp, tmp_cnt[5005], f[5005], cur;

int main()
{
    memset(cnt_a, 0, sizeof(cnt_a));
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        cnt_a[a[i]]++;
        if (cnt_a[a[i]] == 1)
            cnt++;
    }
    for (i = 1; i <= n; i++)
    {
        tmp = cur = 0;
        memset(tmp_cnt, 0, sizeof(tmp_cnt));
        for (j = i; j >= 1; j--)
        {
            tmp_cnt[a[j]]++;
            if (tmp_cnt[a[j]] == 1)
            {
                tmp++;
                cur = cur ^ a[j];
            }
            if (tmp_cnt[a[j]] == cnt_a[a[j]])
                tmp--;
            if (tmp == 0)
            {
                f[i] = f[j - 1] + cur;
                break;
            }
        }
        f[i] = max(f[i], f[i - 1]);
    }
    printf("%d", f[n]);
}