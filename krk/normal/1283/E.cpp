#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int x[Maxn];

int solveMin()
{
    int lst = -1;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (lst >= x[i] - 1) ;
        else { res++; lst = x[i] + 1; }
    return res;
}

int solveMax()
{
    int lst = -1;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (lst >= x[i] + 1) ;
        else { res++; lst = max(lst + 1, x[i] - 1); }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    printf("%d %d\n", solveMin(), solveMax());
    return 0;
}