#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int t, m, n = 0;
string s;

long long used[2000];
long long usep[2000];
int cnt[2000];

int main()
{
    cin >> t >> m;
    for (int i = 1; i <= t; i ++)
    {
        cin >> s;
        if (s == "alloc")
        {
            int p; cin >> p;

            bool good = false;
            for (int j = 1; j <= m; j ++)
                if (j + p - 1 > m) break; else
                if (cnt[j + p - 1] == cnt[j - 1])
                {
                    n ++;
                    for (int k = j; k <= j + p - 1; k ++)
                        used[k] = n;
                    printf("%d\n", n);
                    good = true;
                    break;
                }

            if (!good) printf("NULL\n");
        } else
        if (s == "erase")
        {
            long long p;
            cin >> p;

            bool good = false;
            for (int j = 1; j <= m; j ++)
                if (used[j] == p)
                {
                    good = true;
                    for (int k = j; k <= m; k ++)
                        if (used[k] == p) used[k] = 0; else break;
                    break;
                }

            if (!good || p == 0)
            {
                 printf("ILLEGAL_ERASE_ARGUMENT\n");
            }
        } else
        {
            int l = 0;
            for (int j = 1; j <= m; j ++)
                usep[j] = 0;

            for (int j = 1; j <= m; j ++)
                if (used[j] != 0)
                    l ++, usep[l] = used[j];

            for (int j = 1; j <= m; j ++)
                used[j] = usep[j];
        }

        for (int j = 1; j <= m; j ++)
        {
            cnt[j] = cnt[j - 1];
            if (used[j] != 0) cnt[j] ++;
        }
    }
    return 0;
}