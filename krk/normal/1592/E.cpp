#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1000005;
const int Maxm = 20;
 
struct node {
    int ch[2];
    node() { ch[0] = ch[1] = 0; }
};
 
int n;
int a[Maxn];
int nxt[Maxn][Maxm];
node st[Maxn * (Maxm + 1)];
int slen;
int R[Maxn];
int res;
 
int createNew() { return slen++; }
 
void Add(int v, int oldv, int lvl, int val)
{
    st[v] = st[oldv];
    if (lvl < 0) return;
    int b = bool(val & 1 << lvl);
    st[v].ch[b] = createNew();
    Add(st[v].ch[b], st[oldv].ch[b], lvl - 1, val);
}
 
int getMax(int v, int lvl, int val, int mask)
{
    if (v == 0 || lvl < 0) return -1;
    int zer = bool(mask & 1 << lvl);
    int one = !zer;
    if (val & 1 << lvl) return max(st[v].ch[zer], getMax(st[v].ch[one], lvl - 1, val, mask));
    else return getMax(st[v].ch[zer], lvl - 1, val, mask);
}
 
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    fill(nxt[n], nxt[n] + Maxm, n);
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < Maxm; j++)
            nxt[i][j] = (a[i] & 1 << j)? nxt[i + 1][j]: i;
    createNew();
    int cur = 0;
    int lst = 0;
    for (int i = 0; i < n; i++) {
        cur ^= a[i];
        R[i] = createNew();
        Add(R[i], lst, Maxm - 1, cur);
        lst = R[i];
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        int valand = a[i];
        int st = i;
        while (st < n) {
            int to = n;
            for (int j = 0; j < Maxm; j++)
                if (valand & 1 << j) to = min(to, nxt[st][j]);
            int got = upper_bound(R, R + n, getMax(R[to - 1], Maxm - 1, valand, cur)) - R - 1;
            if (got >= i) res = max(res, got - i + 1);
            valand &= a[to];
            st = to;
        }
        cur ^= a[i];
    }
    printf("%d\n", res);
    return 0;
}