#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n, q;
int a[Maxn];
int k[Maxn];

bool Check(int x)
{
    int cnt = upper_bound(a, a + n, x) - a;
    for (int i = 0; i < q; i++)
        if (k[i] > 0) cnt += k[i] <= x;
        else {
            int rem = -k[i];
            if (rem <= cnt) cnt--;
        }
    return cnt >= 1;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < q; i++)
        scanf("%d", &k[i]);
    int lef = 1, rig = Maxn;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    if (lef > Maxn) printf("0\n");
    else printf("%d\n", lef);
    return 0;
}