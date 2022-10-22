#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, q;
int par[Maxn], siz[Maxn];
int mx[Maxn];
set <ii> S;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    mx[a] = max(mx[a], mx[b]);
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
        mx[i] = -1;
        S.insert(ii(i, i));
    }
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            if (x == 0) {
                auto it = S.lower_bound(ii(l, 0)); it--;
                int lef = it->first, rig = it->second;
                while (it != S.end() && it->first <= r) {
                    unionSet(lef, it->first);
                    rig = it->second;
                    S.erase(it++);
                }
                S.insert(ii(lef, rig));
            } else mx[getPar(r)] = max(mx[getPar(r)], l - 1);
        } else {
            int x; scanf("%d", &x);
            if (getPar(x) == getPar(x - 1)) printf("NO\n");
            else if (mx[getPar(x)] != -1 && getPar(mx[getPar(x)]) == getPar(x - 1)) printf("YES\n");
            else printf("N/A\n");
        }
    }
    return 0;
}