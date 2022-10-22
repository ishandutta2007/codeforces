#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
int a[Maxn];

bool Check(int d)
{
    int lft = d, pen = 0;
    int acc = 0;
    for (int i = n - 1; i >= 0 && acc < m; i--) {
        if (lft == 0) { lft = d; pen++; }
        lft--;
        acc += max(0, a[i] - pen);
    }
    return acc >= m;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int lef = 1, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    int res = rig + 1;
    if (res > n) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}