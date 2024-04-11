#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 15;
const int Maxm = 5005;

int n;
int cnt[Maxn], B[Maxn][Maxm];
ll sum[Maxn];
ll nd;
map <ll, int> M;
ii st[1 << Maxn];
int par[1 << Maxn];
ii res[Maxn];

int Solve(int v, int give, int mask, int r, int rgive)
{
    if (!(mask & 1 << v)) {
        mask |= 1 << v;
        ll nxt = nd - (sum[v] - give);
        map <ll, int>::iterator it = M.find(nxt);
        if (it == M.end()) return -1;
        return Solve(it->second, nxt, mask, r, rgive);
    } else if (v == r && give == rgive) return mask;
           else return -1;
}

void Print(int v, int give, int mask)
{
    if (!(mask & 1 << v)) {
        mask |= 1 << v;
        ll nxt = nd - (sum[v] - give);
        int ind = M[nxt];
        res[ind] = ii(int(nxt), v);
        Print(ind, nxt, mask);
    }
}

void Gen(int lvl, int big, int small)
{
    if (lvl >= n) {
        if (st[small].first != -1 && par[big ^ small] != 0)
            par[big] = small;
    } else {
        Gen(lvl + 1, big, small);
        Gen(lvl + 1, big | 1 << lvl, small);
        Gen(lvl + 1, big | 1 << lvl, small | 1 << lvl);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cnt[i]);
        for (int j = 0; j < cnt[i]; j++) {
            scanf("%d", &B[i][j]);
            nd += B[i][j];
            sum[i] += B[i][j];
            M[B[i][j]] = i;
        }
    }
    if (nd % n != 0) { printf("No\n"); return 0; }
    nd /= n;
    fill((ii*)st, (ii*)st + (1 << Maxn), ii(-1, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < cnt[i]; j++) {
            int mask = Solve(i, B[i][j], 0, i, B[i][j]);
            if (mask != -1) st[mask] = ii(i, B[i][j]);
        }
    par[0] = -1;
    Gen(0, 0, 0);
    int all = (1 << n) - 1;
    if (!par[all]) { printf("No\n"); return 0; }
    printf("Yes\n");
    while (all) {
        int mask = par[all];
        all ^= mask;
        Print(st[mask].first, st[mask].second, 0);
    }
    for (int i = 0; i < n; i++)
        printf("%d %d\n", res[i].first, res[i].second + 1);
    return 0;
}