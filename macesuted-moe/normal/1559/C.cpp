#include <bits/stdc++.h>

inline int read()
{
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while ( isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}

int a[100010];

int main()
{
    for (int T = read(); T; --T)
    {
        int n = read(), t = 0;
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        for (int i = n; i >= 1; --i)
            if (a[i] == 0)
            {
                t = i;
                break;
            }
        if (t == 0)
        {
            printf("%d ", n + 1);
            for (int i = 1; i <= n; ++i)
                printf("%d ", i);
            puts("");
            continue;
        }
        std::vector<int> vec;
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", i);
            if (i == t)
                printf("%d ", n + 1);
        }
        putchar('\n');
    }
    return 0;
}