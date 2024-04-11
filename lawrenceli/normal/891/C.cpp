#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 500100;

int n, m, q;
pair<int, pair<int, int> > edges[maxn];

int par[maxn], rnk[maxn];
stack<pair<pair<int, int>, int> > stk;

int getpar(int a) {
    while (par[a] != a) a = par[a];
    return a;
}

void merge(int a, int b) {
    a = getpar(a), b = getpar(b);
    if (rnk[a] > rnk[b]) swap(a, b);
    par[a] = b;
    stk.push(MP(MP(a, b), rnk[b]));
    if (rnk[a] == rnk[b]) rnk[b]++;
}

void rollback() {
    int a = stk.top().A.A, b = stk.top().A.B, r = stk.top().B;
    stk.pop();
    par[a] = a;
    rnk[b] = r;
}

bool good[maxn];
vector< pair< vector<pair<int, int> >, int> > qry[maxn];

int qi[maxn];

bool cmp(int i1, int i2) {
    return edges[i1].A < edges[i2].A;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[i] = MP(c, MP(a, b));
    }

    int q; scanf("%d", &q);
    for (int ii = 0; ii < q; ii++) {
        good[ii] = 1;
        int k; scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &qi[i]);
            qi[i]--;
        }
        sort(qi, qi + k, cmp);

        for (int i = 0, j; i < k; i = j) {
            int c = edges[qi[i]].A;
            vector<pair<int, int> > v;
            for (j = i; j < k && edges[qi[j]].A == c; j++) {
                int a = edges[qi[j]].B.A, b = edges[qi[j]].B.B;
                v.push_back(MP(a, b));
            }
            qry[c].push_back(MP(v, ii));
        }
    }

    sort(edges, edges + m);

    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 0, j; i < m; i = j) {
        int c = edges[i].A;

        for (auto ii : qry[c]) {
            vector<pair<int, int> > v = ii.A;
            int x = ii.B;

            for (auto p : v) {
                int a = p.A, b = p.B;
                if (getpar(a) == getpar(b)) {
                    good[x] = 0;
                    break;
                }

                merge(a, b);
            }

            while (!stk.empty()) rollback();
        }

        for (j = i; j < m && edges[j].A == c; j++) {
            int a = edges[j].B.A, b = edges[j].B.B;
            if (getpar(a) != getpar(b)) merge(a, b);
        }

        while (!stk.empty()) stk.pop();
    }

    for (int i = 0; i < q; i++)
        if (good[i]) printf("YES\n");
        else printf("NO\n");
}