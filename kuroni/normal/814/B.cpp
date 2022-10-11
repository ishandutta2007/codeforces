#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> ans;
int n, i, a[1005], b[1005], p[1005], save_i = 0, save_j = 0;
bool chk[1005];

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (i = 1; i <= n; i++)
        scanf("%d", b + i);
    for (i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
        {
            p[i] = a[i];
            chk[p[i]] = 1;
        }
        else
        {
            if (save_i == 0)
                save_i = i;
            else save_j = i;
        }
    }
    if (save_j == 0)
    {
        for (i = 1; i <= n; i++)
            if (!chk[i])
                p[save_i] = i;
    }
    else
    {
        for (i = 1; i <= n; i++)
            if (!chk[i])
                ans.push_back(i);
        if (((a[save_i] != ans[0]) != (a[save_j] != ans[1])) && ((b[save_i] != ans[0]) != (b[save_j] != ans[1])))
        {
            p[save_i] = ans[0];
            p[save_j] = ans[1];
        }
        else
        {
            p[save_i] = ans[1];
            p[save_j] = ans[0];
        }
    }
    for (i = 1; i <= n; i++)
        printf("%d ", p[i]);
}