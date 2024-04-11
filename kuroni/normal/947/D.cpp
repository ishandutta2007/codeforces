    #include <iostream>
    #include <cstdio>
    #include <cstring>
    using namespace std;

    const int MAX = 100005;

    int q, l, r, x, y, n[2], sum[2][MAX], lst[2][MAX];
    char s[2][MAX];

    int main()
    {
        scanf("%s\n%s\n%d\n", s[0] + 1, s[1] + 1, &q);
        for (int mask = 0; mask < 2; mask++)
        {
            n[mask] = strlen(s[mask] + 1);
            for (int i = 1; i <= n[mask]; i++)
            {
                sum[mask][i] = sum[mask][i - 1] + (s[mask][i] != 'A');
                lst[mask][i] = (s[mask][i] == 'A' ? lst[mask][i - 1] + 1 : 0);
            }
        }
        while (q--)
        {
            scanf("%d %d %d %d\n", &l, &r, &x, &y);
            if (min(lst[0][r], r - l + 1) < min(lst[1][y], y - x + 1))
                printf("0");
            else if (min(lst[0][r], r - l + 1) == min(lst[1][y], y - x + 1) && sum[0][r] - sum[0][l - 1] == 0 && sum[1][y] - sum[1][x - 1] > 0)
                printf("0");
            else
            {
                int ad = (min(lst[0][r], r - l + 1) - min(lst[1][y], y - x + 1)) % 3,
                    le = sum[0][r] - sum[0][l - 1] + (ad ? 2 : 0), 
                    ri = sum[1][y] - sum[1][x - 1];
                if (le <= ri && !((ri - le) & 1))
                    printf("1");
                else
                    printf("0");
            }
        }
    }