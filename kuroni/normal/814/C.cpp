#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s;
char c;
short int ans[1505][1505][30], tmp[1505][30];
int i, j, k, n, q;

int find_ans(int i, int m, int x)
{
    if (i == n)
        return 0;
    if (ans[i][j][x] != -1)
        return ans[i][j][x];
    if (s[i] - 'a' != x && m == 0)
        ans[i][j][x] = 0;
    else
    {
        if (s[i] - 'a' == x)
            ans[i][j][x] = find_ans(i + 1, m, x) + 1;
        else ans[i][j][x] = find_ans(i + 1, m - 1, x) + 1;
    }
    tmp[m][x] = max(tmp[m][x], ans[i][j][x]);
    return ans[i][j][x];
}

int main()
{
    cin >> n >> s;
    memset(ans, -1, sizeof(ans));
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            for (k = 0; k <= 'z' - 'a'; k++)
            find_ans(i, j, k);
    scanf("%d\n", &q);
    while (q--)
    {
        scanf("%d %c\n", &k, &c);
        printf("%d\n", tmp[k][c - 'a']);
    }
}