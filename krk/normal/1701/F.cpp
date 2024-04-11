#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400005;
const int Maxm = 2097152;

ll cnt[Maxm], cur[Maxm], tot[Maxm];
ll flag[Maxm];
int n, d;
bool my[Maxn];
int BIT[Maxn];

void Insert(int x, int val)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i] += val;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

ll Add(int hm) { return ll(hm - 1) * hm / 2; }

void Down(int v, ll f)
{
    if (f > 0) {
        tot[v] += cur[v] * f + Add(f) * cnt[v];
    } else if (f < 0) {
        tot[v] += cur[v] * f + Add(-f + 1) * cnt[v];
    }
    cur[v] += cnt[v] * f;
    flag[v] += f;
}

void Down(int v)
{
    if (flag[v]) {
        Down(2 * v, flag[v]);
        Down(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    cnt[v] = cnt[lc] + cnt[rc];
    cur[v] = cur[lc] + cur[rc];
    tot[v] = tot[lc] + tot[rc];
}

void Update(int v, int l, int r, int a, int b, int delt)
{
    if (l == a && r == b) Down(v, delt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

void Switch(int v, int l, int r, int x)
{
    if (l == r) {
        if (my[x]) {
            cnt[v] = 1;
            cur[v] = Get(x - 1) - Get(max(0, x - d - 1));
            tot[v] = Add(cur[v]);
        } else cnt[v] = cur[v] = tot[v] = 0;
    } else {
        Down(v);
        int m = l + r >> 1;
        if (x <= m) Switch(2 * v, l, m, x);
        else Switch(2 * v + 1, m + 1, r, x);
        Union(v);
    }
}

int main()
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        my[a] ^= true;
        int delt = my[a]? 1: -1; 
        Insert(a, delt);
        Update(1, 0, Maxn - 1, a + 1, a + d, delt);
        Switch(1, 0, Maxn - 1, a);
        printf("%I64d\n", tot[1]);
    }
    return 0;
}