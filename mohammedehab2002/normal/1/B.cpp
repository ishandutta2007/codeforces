#include <stdio.h>
#include <string.h>
void convert_to_second(char c[])
{
    int d[20];
    int k = -1, x = 0;
    int n = strlen(c);
    for (int i = 0; i < n; i ++)
        if (c[i] - 'A' >= 0 && c[i] - 'Z' <= 0) k ++, d[k] = c[i] - 'A' + 1; else x = x * 10 + (c[i] - '0');
    printf("R%dC", x);
    int y = 0;
    for (int i = 0; i <= k; i ++)
        y = y * 26 + d[i];
    printf("%d\n", y);
}

void convert_to_first(int x, int y)
{
    int d[20], k = -1;
    while (y > 0)
    {
        int t = y % 26;
        if (t != 0) k ++, d[k] = t, y /= 26; else
        {
            k ++; d[k] = 26; y -= 26; y /= 26;
        }
    }

    for (int i = k; i >= 0; i --)
        printf("%c", 'A' - 1 + d[i]);
    printf("%d\n", x);
}

void solve()
{
    char c[50];
    gets(c);

    int x, y;
    if (sscanf(c, "R%dC%d", &x, &y) == 2)
        convert_to_first(x, y); else
        convert_to_second(c);
}

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i ++)
        solve();
    return 0;
}