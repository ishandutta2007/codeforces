#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

const int N = 2005;

int t, n, m, u, v, cnt, ans[N];
bitset<N> bit[N];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = 0;
            bit[i].reset();
        }
        while (m--)
        {
            scanf("%d%d", &u, &v);
            bit[u].flip(u); bit[u].flip(v); bit[u].flip(0);
            bit[v].flip(u); bit[v].flip(v); bit[v].flip(0);
        }
        for (int i = 1; i <= n; i++)
        {
            int pt = 0;
            for (int j = i; j <= n; j++)
                if (bit[j][i])
                {
                    pt = j;
                    break;
                }
            if (pt != 0)
            {
                swap(bit[i], bit[pt]);
                for (int j = i + 1; j <= n; j++)
                    if (bit[j][i])
                        bit[j] ^= bit[i];
            }
            else
                for (int j = i; j <= n; j++)
                    if (bit[j].count() == 0)
                    {
                        swap(bit[i], bit[j]);
                        break;
                    }
        }
        for (int i = n; i >= 1; i--)
        {
            ans[i] = bit[i][0];
            for (int j = i + 1; j <= n; j++)
                if (bit[i][j])
                    ans[i] ^= ans[j];
            cnt = max(cnt, ans[i]);
        }
        printf("%d\n", cnt + 1);
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i] + 1);
        printf("\n");
    }
}