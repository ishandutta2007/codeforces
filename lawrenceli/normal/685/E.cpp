#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 1005;
const int maxm = 200100;
const int inf = 1e9;

int n, m, q;
int ea[maxm], eb[maxm];

vector<pair<pair<int, int>, pair<int, int> > > qry[maxm];

int dist[maxn][maxn];
bool ans[maxm];
int rec[maxn];

void add(int a, int b, int i) {
    if (rec[b] < dist[a][b]) {
        for (int j = 1; j <= n; j++)
            if (dist[b][j] < dist[a][j])
                dist[a][j] = dist[b][j];
    }
    dist[a][b] = i;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ea[i], &eb[i]);
    }

    for (int i = 0; i < q; i++) {
        int l, r, s, t;
        scanf("%d %d %d %d", &l, &r, &s, &t);
        l--, r--;
        qry[l].push_back(MP(MP(s, t), MP(r, i)));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dist[i][j] = inf;

    for (int i = 1; i <= n; i++) rec[i] = inf;
    for (int i = m - 1; i >= 0; i--) {
        add(ea[i], eb[i], i);
        add(eb[i], ea[i], i);
        rec[ea[i]] = rec[eb[i]] = i;

        for (auto j : qry[i])
            ans[j.B.B] = dist[j.A.A][j.A.B] <= j.B.A;
    }

    for (int i = 0; i < q; i++) {
        if (ans[i]) printf("Yes\n");
        else printf("No\n");
    }
}