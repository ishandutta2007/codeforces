#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 2097152;
const int mod = 998244353;

struct node {
    int fir, lst;
    int dp[2][2];
    node() {
        fir = lst = 0;
        fill((int*)dp, (int*)dp + 2 * 2, 0);
    }
};

int n, m;
char str[Maxn];
node st[Maxm];

int Get(int dig) { return dig + 1; }

int Get(int dig1, int dig2)
{
    if (dig1 != 1) return 0;
    return 19 - (10 * dig1 + dig2);
}

node Union(const node &a, const node &b)
{
    node res;
    res.fir = a.fir;
    res.lst = b.lst;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            res.dp[i][j] = (ll(a.dp[i][0]) * b.dp[0][j] + ll(a.dp[i][1]) * ll(b.dp[1][j]) % mod * Get(a.lst, b.fir)) % mod;
    return res;
}

node setNew(int val)
{
    node res;
    res.fir = res.lst = val;
    res.dp[0][1] = res.dp[1][0] = 1;
    res.dp[0][0] = Get(val);
    return res;
}

void Create(int v, int l, int r)
{
    if (l == r) st[v] = setNew(str[l] - '0');
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int x, int val)
{
    if (l == r) st[v] = setNew(val);
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, val);
        else Update(2 * v + 1, m + 1, r, x, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", str + 1);
    Create(1, 1, n);
    while (m--) {
        int ind, val; scanf("%d %d", &ind, &val);
        Update(1, 1, n, ind, val);
        printf("%d\n", st[1].dp[0][0]);
    }
    return 0;
}