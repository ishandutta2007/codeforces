#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000000;

int n, m, k;
char res[Maxn];
int rlen;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m - 1; i++)
        res[rlen++] = 'L';
    for (int i = 0; i < n - 1; i++)
        res[rlen++] = 'U';
    int r = 0, c = 0;
    while (true)
        if (r % 2 == 0)
            if (c + 1 < m) { res[rlen++] = 'R'; c++; }
            else if (r + 1 < n) { res[rlen++] = 'D'; r++; }
            else break;
        else if (c - 1 >= 0) { res[rlen++] = 'L'; c--; }
             else if (r + 1 < n) { res[rlen++] = 'D'; r++; }
             else break;
    res[rlen] = '\0';
    printf("%d\n%s\n", rlen, res);
    return 0;
}