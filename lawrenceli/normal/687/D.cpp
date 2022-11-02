#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 1005;

int n, m, q;
pair<pair<int, int>, pair<int, int> > edges[maxn * maxn];
pair<int, int> par[maxn];

pair<int, int> getpar(int a) {
    if (par[a].A == a) return par[a];
    pair<int, int> p = getpar(par[a].A);
    return par[a] = MP(p.A, p.B ^ par[a].B);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].B.A, &edges[i].B.B, &edges[i].A.A);
        edges[i].A.B = i;
    }
    sort(edges, edges + m); reverse(edges, edges + m);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        for (int j = 1; j <= n; j++) par[j] = MP(j, 0);
        bool b = 0;
        for (int j = 0; j < m; j++)
            if (l <= edges[j].A.B && edges[j].A.B < r) {
                pair<int, int> x = getpar(edges[j].B.A), y = getpar(edges[j].B.B);
                if (x.A == y.A) {
                    if (x.B == y.B) {
                        printf("%d\n", edges[j].A.A);
                        b = 1;
                        break;
                    }
                } else {
                    par[x.A] = MP(y.A, x.B ^ y.B ^ 1);
                }
            }

        if (!b) printf("-1\n");
    }
}