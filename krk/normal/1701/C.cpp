#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m;
int has[Maxn];

bool Check(int x)
{
    ll st = 0;
    for (int i = 1; i <= n; i++)
        if (has[i] <= x) st += (x - has[i]) / 2;
        else st -= (has[i] - x);
    return st >= 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(has, has + n + 1, 0);
        for (int i = 0; i < m; i++) {
            int a; scanf("%d", &a);
            has[a]++;
        }
        int lef = 0, rig = 2 * m;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check(mid)) rig = mid - 1;
            else lef = mid + 1;
        }
        printf("%d\n", lef);
    }
    return 0;
}