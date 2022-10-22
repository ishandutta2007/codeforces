#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, z;
int x[Maxn];

int main()
{
    scanf("%d %d", &n, &z);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    int lef = 1, rig = n / 2;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        bool ok = true;
        for (int i = 0; i < mid && ok; i++)
            ok = x[n - mid + i] - x[i] >= z;
        if (ok) lef = mid + 1;
        else rig = mid - 1;
    }
    printf("%d\n", lef - 1);
    return 0;
}