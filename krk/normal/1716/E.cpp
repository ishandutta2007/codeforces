#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxk = 18;

struct pos {
    ll lef, sum, rig;
    ll best;
    pos(int x = 0) {
        lef = max(0, x);
        sum = x;
        rig = max(0, x);
        best = max(0, x);
    }
};

int n;
int a[1 << Maxk];
vector <pos> dp[1 << Maxk];

pos Union(const pos &a, const pos &b)
{
    pos c;
    c.lef = max(a.lef, a.sum + b.lef);
    c.rig = max(a.rig + b.sum, b.rig);
    c.sum = a.sum + b.sum;
    c.best = max(a.rig + b.lef, max(a.best, b.best));
    return c;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++) {
        scanf("%d", &a[i]);
        dp[0].push_back(pos(a[i]));
    }
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < 1 << i; mask++) {
            vector <pos> tmp = dp[mask]; dp[mask].clear();
            for (int j = 0; j < tmp.size(); j += 2) {
                dp[mask].push_back(Union(tmp[j], tmp[j + 1]));
                dp[mask | 1 << i].push_back(Union(tmp[j + 1], tmp[j]));
            }
        }
    int cur = 0;
    int q; scanf("%d", &q);
    while (q--) {
        int b; scanf("%d", &b);
        cur ^= 1 << b;
        printf("%I64d\n", dp[cur][0].best);
    }
    return 0;
}