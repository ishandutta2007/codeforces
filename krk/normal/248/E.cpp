#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int Maxn = 100005;
const int Maxm = 101;

int n;
ld prob[Maxn][Maxm];
int all[Maxn];
int q;
ld res;

ld Mult(ld val, int l1, int r1, int l2, int r2)
{
    while (l1 <= r1 || l2 <= r2)
        if (l1 <= r1 && (l2 > r2 || val < 1)) { val *= l1; l1++; }
        else { val /= l2; l2++; }
    return val;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &all[i]);
        prob[i][all[i]] = 1;
        res += prob[i][0];
    }
    scanf("%d", &q);
    while (q--) {
        int u, v, k; scanf("%d %d %d", &u, &v, &k);
        res -= prob[u][0];
        for (int i = 0; i < Maxm && i <= all[u]; i++) if (prob[u][i] > 0) {
            ld p = prob[u][i]; prob[u][i] = 0;
            for (int j = 0; j <= k; j++) if (j <= i && k - j <= all[u] - i) {
                ld my = Mult(p, i - j + 1, i, 1, j);
                my = Mult(my, 1, k, all[u] - k + 1, all[u]);
                my = Mult(my, all[u] - i - k + j + 1, all[u] - i, 1, k - j);
                prob[u][i - j] += my;
            }
        }
        all[u] -= k; all[v] += k;
        res += prob[u][0];
        printf("%.10f\n", double(res));
    }
    return 0;
}