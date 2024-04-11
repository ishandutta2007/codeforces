#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int a[Maxn];
int q;
vector <int> V[Maxn];
set <int> S;
int val1[Maxn], val2[Maxn];
ll sum1[Maxn], sum2[Maxn];
ll res;

ii getRange(int a, int b)
{
    return ii(lower_bound(val1 + 1, val1 + n + 1, a) - val1, upper_bound(val1 + 1, val1 + n + 1, b) - val1 - 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int my = max(1, i - (a[i] - 1));
        V[my].push_back(i);
    }
    S.insert(n + 1);
    S.insert(n + 2);
    for (int i = n; i > 0; i--) {
        auto it = S.lower_bound(i);
        res += *it - i;
        val1[i] = *it;
        it++;
        val2[i] = *it;
        for (int j = 0; j < V[i].size(); j++)
            S.insert(V[i][j]);
    }
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i - 1] + val1[i];
        sum2[i] = sum2[i - 1] + val2[i];
    }
    int q; scanf("%d", &q);
    while (q--) {
        int ind, val; scanf("%d %d", &ind, &val);
        int old = max(1, ind - (a[ind] - 1));
        int nw = max(1, ind - (val - 1));
        ll nres = res;
        if (old < nw) {
            int lef = old, rig = nw - 1;
            ii got = getRange(ind + 1, Maxn);
            lef = max(lef, got.first); rig = min(rig, got.second);
            if (lef > rig) { printf("%I64d\n", res); continue; }
            nres -= ((sum1[rig] - sum1[lef - 1]) - ll(ind) * (rig - lef + 1));
        } else if (old > nw) {
            int lef = nw, rig = old - 1;
            ii got = getRange(ind, ind);
            lef = max(lef, got.first); rig = min(rig, got.second);
            if (lef > rig) { printf("%I64d\n", res); continue; }
            nres += ((sum2[rig] - sum2[lef - 1]) - ll(ind) * (rig - lef + 1));
        }
        printf("%I64d\n", nres);
    }
    return 0;
}