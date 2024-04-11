#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    node *next;
    int where;
} *first[200001], a[400001];

int l, n, m, K, d[200001], v[10][10], c[200001][3];
long long f[200001];
vector<int> e[200001], w[200001];
bool b[46][46], rr[46], ll[46];
int ans = 0;

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

inline void soso(int i) {
    if (i == K + 1) {
        ++ans;
        return;
    }
    for (int j = 1; j <= i; j++) {
        bool ok = true;
        if (ll[v[i][j]])
            ok = false;
        for (int k = 0; k < v[i][j]; k++)
            if (b[k][v[i][j]] && rr[k])
                ok = false;
        if (ok) {
            rr[v[i][j]] = true;
            soso(i + 1);
            rr[v[i][j]] = false;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ++d[y];
        e[x].push_back(y);
        w[x].push_back(z);
        makelist(y, x);
    }
    for (int i = 1; i <= n; i++)
        if (!d[i]) {
            printf("0\n");
            return 0;
        }
    int cnt = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= i; j++)
            v[i][j] = cnt++;
    bool ok = true;
    for (int i = 1; i <= n && ok; i++) {
        long long s = 0, t = 0;
        for (node *x = first[i]; x && ok; x = x->next) {
            int len = e[x->where].size(), pos = 0;
            for (int j = 0; j < len; j++)
                if (e[x->where][j] == i)
                    pos = j;
            int tot = 1;
            for (int j = 0; j < len; j++)
                if (w[x->where][j] < w[x->where][pos])
                    ++tot;
            if (s & (1LL << v[len][tot]))
                t |= (1LL << v[len][tot]);
            s |= (1LL << v[len][tot]);
        }
        for (int j = 0; j < 45; j++)
            if (t & (1LL << j))
                ll[j] = true;
        for (int j = 0; j < 45; j++)
                if (s & (1LL << j))
            for (int k = 0; k < 45; k++)
                    if (s & (1LL << k))
                        if (j != k)
                            b[j][k] = true;
    }
    for (int i = 1; i <= 9; i++)
        for (int k = 1; k <= i; k++)
            for (int l = k + 1; l <= i; l++)
                b[v[i][k]][v[i][l]] = b[v[i][l]][v[i][k]] = true;
    if (!ok) {
        printf("0\n");
        return 0;
    }
    soso(1);
    printf("%d\n", ans);
}