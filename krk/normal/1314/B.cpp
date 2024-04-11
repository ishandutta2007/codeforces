#include <bits/stdc++.h>
using namespace std;

const int Maxn = (1 << 17) + 5;
const int Inf = 1000000000;
const int Maxd = 2;

struct pos {
    int dp[Maxd][Maxd];
    pos() { fill((int*)dp, (int*)dp + Maxd * Maxd, -Inf); }
};

int n, k;
bool tk[Maxn];
int sum[Maxn];
int res;

pos Get(int l, int r)
{
    pos res;
    if (l + 1 == r) {
        res.dp[tk[l]][tk[r]] = (tk[l] || tk[r]);
        res.dp[tk[r]][tk[l]] = (tk[l] || tk[r]);
        return res;
    }
    int m = l + r >> 1;
    pos A = Get(l, m);
    pos B = Get(m + 1, r);
    for (int a1 = 0; a1 < Maxd; a1++)
        for (int a2 = 0; a2 < Maxd; a2++)
            for (int b1 = 0; b1 < Maxd; b1++)
                for (int b2 = 0; b2 < Maxd; b2++)
                    for (int w1 = 0; w1 < Maxd; w1++)
                        for (int w2 = 0; w2 < Maxd; w2++)
                            for (int w3 = 0; w3 < Maxd; w3++) {
                                int cand = A.dp[a1][a2] + B.dp[b1][b2];
                                if (a1 || b1) cand++;
                                int k1 = w1? a1: b1;
                                int k2 = w1? b1: a1;
                                if (a2 || b2) cand++;
                                int k3 = w2? a2: b2;
                                if (k2 || k3) cand++;
                                k2 = w3? k2: k3;
                                res.dp[k1][k2] = max(res.dp[k1][k2], cand);
                            }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    n = 1 << n;
    for (int i = 0; i < k; i++) {
        int a; scanf("%d", &a);
        tk[a] = true;
    }
    int res = -Inf;
    pos got = Get(1, n);
    for (int a = 0; a < Maxd; a++)
        for (int b = 0; b < Maxd; b++)
            res = max(res, got.dp[a][b] + int(a || b));
    printf("%d\n", res);
    return 0;
}