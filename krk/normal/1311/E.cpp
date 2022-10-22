#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int mn[Maxn], mx[Maxn];
int nxt;
int par[Maxn];
int T;
int n, k;

bool Possible(int n, int k)
{
    return mn[n] <= k && k <= n * (n - 1) / 2;
}

void Solve(int v, int n, int k)
{
    if (n == 1) return;
    k -= (n - 1);
    if (mn[n - 1] <= k && k <= mx[n - 1]) {
        par[++nxt] = v;
        Solve(nxt, n - 1, k);
        return;
    }
    int lef = 1, rig = (n - 1) / 2;
    while (lef <= rig) {
        int a = lef + rig >> 1;
        int b = n - 1 - a;
        if (mn[a] + mn[b] <= k && k <= mx[a] + mx[b]) {
            int ka = mn[a];
            int kb = k - ka;
            if (kb > mx[b]) {
                int tk = kb - mx[b];
                ka += tk; kb -= tk;
            }
            par[++nxt] = v;
            Solve(nxt, a, ka);
            par[++nxt] = v;
            Solve(nxt, b, kb);
            return;
        } else if (k < mn[a] + mn[b]) lef = a + 1;
               else rig = a - 1;
    }
}

int main()
{
    mn[0] = 0;
    int wh = 0, cnt = 1, lft = 1;
    for (int i = 1; i < Maxn; i++) {
        mn[i] = mn[i - 1] + wh;
        if (--lft == 0) { wh++; cnt *= 2; lft = cnt; }
        mx[i] = i * (i - 1) / 2;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (mn[n] <= k && k <= mx[n]) {
            printf("YES\n");
            nxt = 1;
            Solve(1, n, k);
            for (int i = 2; i <= n; i++)
                printf("%d%c", par[i], i + 1 <= n? ' ': '\n');
        } else printf("NO\n");
    }
    return 0;
}