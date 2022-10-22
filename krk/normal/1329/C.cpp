#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = (1 << 20) + 5;

int T;
int h, g;
int n, m;
int a[Maxn];
bool tk[Maxn];

bool Remove(int ind)
{
    int lef = 2 * ind, rig = 2 * ind + 1;
    if (lef > n || (a[lef] == 0 && a[rig] == 0))
        if (ind <= m) { tk[ind] = true; return false; }
        else { tk[ind] = true; a[ind] = 0; return true; }
    if (a[lef] > a[rig]) {
        int mem = a[lef];
        if (!Remove(lef)) { tk[ind] = true; return false; }
        a[ind] = mem;
        return true;
    } else {
        int mem = a[rig];
        if (!Remove(rig)) { tk[ind] = true; return false; }
        a[ind] = mem;
        return true;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &h, &g);
        n = (1 << h) - 1;
        m = (1 << g) - 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            tk[i] = false;
        }
        vector <int> res;
        for (int i = 1; i <= n; i++)
            while (!tk[i] && Remove(i)) res.push_back(i);
        ll ans = 0;
        for (int i = 1; i <= m; i++)
            ans += a[i];
        printf("%I64d\n", ans);
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}