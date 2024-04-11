#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 1005;

int n, q;
int a[Maxn];
int qa[Maxn], qb[Maxn];
int nxt[Maxn][Maxn];
ld dpa[Maxn][Maxn], dpb[Maxn][Maxn];
ld res;

ld Get(int from, int a, int b)
{
    int r = min(nxt[from][a], nxt[from][b]);
    if (r >= q) return a < b;
    if (qa[r] == a) return dpa[r][b];
    if (qa[r] == b) return 1 - dpa[r][a];
    if (qb[r] == a) return dpb[r][b];
    if (qb[r] == b) return 1 - dpb[r][a];
}

int Change(int quer, int x)
{
    if (qa[quer] == x) x = qb[quer];
    else if (qb[quer] == x) x = qa[quer];
    return x;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        qa[i]--; qb[i]--;
    }
    for (int j = 0; j < n; j++)
        nxt[q][j] = q;
    for (int i = q - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][qa[i]] = nxt[i][qb[i]] = i;
        for (int j = 0; j < n; j++) {
            if (j != qa[i]) {
                int a = qa[i], b = j;
                ld lst = Get(i + 1, a, b);
                a = Change(i, a), b = Change(i, b);
                dpa[i][j] = (lst + Get(i + 1, a, b)) / 2.0l;
            }
            if (j != qb[i]) {
                int a = qb[i], b = j;
                ld lst = Get(i + 1, a, b);
                a = Change(i, a), b = Change(i, b);
                dpb[i][j] = (lst + Get(i + 1, a, b)) / 2.0l;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (a[i] > a[j])
            res += Get(0, i, j);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}