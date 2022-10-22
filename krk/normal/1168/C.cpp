#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxb = 20;

int n, q;
int a[Maxn];
int dp[Maxb][Maxb];
int my[Maxb];
int qa[Maxn], qb[Maxn];
vector <int> quer[Maxn];
bool qres[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        quer[qa[i]].push_back(i);
    }
    fill((int*)dp, (int*)dp + Maxb * Maxb, n + 1);
    for (int i = n; i >= 1; i--) {
        fill(my, my + Maxb, n + 1);
        for (int j = 0; j < Maxb; j++) if (a[i] & 1 << j)
            for (int k = 0; k < Maxb; k++)
                if (a[i] & 1 << k) my[k] = i;
                else my[k] = min(my[k], dp[j][k]);
        for (int j = 0; j < quer[i].size(); j++) {
            int ind = quer[i][j];
            bool ok = false;
            for (int k = 0; k < Maxb && !ok; k++) if (a[qb[ind]] & 1 << k)
                ok = my[k] < qb[ind];
            qres[ind] = ok;
        }
        for (int j = 0; j < Maxb; j++) if (a[i] & 1 << j)
            for (int k = 0; k < Maxb; k++)
                dp[j][k] = min(dp[j][k], my[k]);
    }
    for (int i = 1; i <= q; i++)
        printf("%s\n", qres[i]? "Shi": "Fou");
    return 0;
}