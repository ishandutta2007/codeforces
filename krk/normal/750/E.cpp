#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Maxd = 5;
const int Inf = 1000000000;

struct node {
    int dp[Maxd][Maxd];
    node(int my = -1) {
        for (int i = 0; i < Maxd; i++) {
            for (int j = i + 1; j < Maxd; j++)
                dp[i][j] = Inf;
            if (my == 2)
                if (i == 0) { dp[i][i + 1] = 0; dp[i][i] = 1; }
                else dp[i][i] = 0;
            else if (my == 0)
                if (i == 1) { dp[i][i + 1] = 0; dp[i][i] = 1; }
                else dp[i][i] = 0;
            else if (my == 1)
                if (i == 2) { dp[i][i + 1] = 0; dp[i][i] = 1; }
                else dp[i][i] = 0;
            else if (my == 7)
                if (i == 3) { dp[i][i + 1] = 0; dp[i][i] = 1; }
                else dp[i][i] = 0;
            else if (my == 6)
                if (i < 3) dp[i][i] = 0;
                else dp[i][i] = 1;
            else dp[i][i] = my == -1? Inf: 0;
        }
    }
    node operator+(const node &b) const {
        node c;
        for (int i = 0; i < Maxd; i++)
            for (int j = i; j < Maxd; j++)
                for (int k = j; k < Maxd; k++)
                    c.dp[i][k] = min(c.dp[i][k], dp[i][j] + b.dp[j][k]);
        return c;
    }
};

int n, q;
char str[Maxn];
node st[Maxm];

void Create(int v, int l, int r)
{
    if (l == r) st[v] = node(str[l] - '0');
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = st[2 * v] + st[2 * v + 1];
    }
}

node Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Get(2 * v, l, m, a, m) + Get(2 * v + 1, m + 1, r, m + 1, b);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    Create(1, 1, n);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int res = Get(1, 1, n, l, r).dp[0][4];
        if (res >= Inf) res = -1;
        printf("%d\n", res);
    }
    return 0;
}