#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int b[Maxn];

bool Solve()
{
    int lef = 0;
    while (lef < n && a[lef] == b[lef]) lef++;
    if (lef >= n) return true;
    if (a[lef] > b[lef]) return false;
    int rig = n - 1;
    while (a[rig] == b[rig]) rig--;
    for (int i = lef; i <= rig; i++)
        if (a[lef] - b[lef] != a[i] - b[i])
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}