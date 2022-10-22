#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, m;
int a[Maxn];

bool Check(int x)
{
    int lst = 0;
    for (int i = 0; i < n; i++)
        if (a[i] + x < m) {
            if (lst > a[i] + x) return false;
            lst = max(lst, a[i]);
        } else {
            int best = m;
            best = min(best, max(lst, a[i]));
            int rig = (a[i] + x) % m;
            if (lst <= rig) best = min(best, lst);
            if (best == m) return false;
            lst = best;
        }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int lef = 0, rig = m - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", rig + 1);
    return 0;
}