#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 60;
const int Maxn = 100005;
const int Maxp = 17;

int n, p;
char str[Maxn];
int nxt[Maxn][Maxp];
int cnt[Maxp];
int A[Maxp][Maxp];
ll fall[1 << Maxp][3];
int res = Maxn;
bool dp[1 << Maxp];
int sum[1 << Maxp];

int Get(int a, int b)
{
    if (a > b) swap(a, b);
    return b * (b + 1) / 2 + a;
}

int main()
{
    scanf("%d %d", &n, &p);
    scanf("%s", str);
    for (int i = 0; i < Maxp; i++)
        nxt[n][i] = n;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < Maxp; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][str[i] - 'a'] = i;
        cnt[str[i] - 'a']++;
    }
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++) {
        int ind = str[i] - 'a';
        int mask = 0;
        int pnt = i + 1;
        while (pnt < n && !(mask & 1 << ind)) {
            int nind = n;
            for (int j = 0; j < p; j++) if (!(mask & 1 << j))
                if (nxt[pnt][j] < nind) nind = nxt[pnt][j];
            pnt = nind;
            if (pnt >= n) break;
            int ind2 = str[pnt] - 'a';
            if (!A[ind][ind2]) {
                int id = Get(ind, ind2);
                fall[mask][id / Maxb] |= 1ll << ll(id % Maxb);
            }
            mask |= 1 << ind2;
        }
    }
    for (int i = 0; i < p; i++)
        for (int j = 0; j < 1 << p; j++)
            if (!(j & 1 << i))
                for (int k = 0; k < 3; k++)
                    fall[j | 1 << i][k] |= fall[j][k];
            else {
                for (int z = 0; z < p; z++) {
                    int id = Get(i, z);
                    if (fall[j][id / Maxb] & 1ll << ll(id % Maxb))
                        fall[j][id / Maxb] ^= 1ll << ll(id % Maxb);
                }
            }
    dp[0] = true;
    for (int i = 0; i < 1 << p; i++) if (dp[i]) {
        if (fall[i][0] || fall[i][1] || fall[i][2]) continue;
        res = min(res, n - sum[i]);
        for (int j = 0; j < p; j++) if (!(i & 1 << j)) {
            dp[i | 1 << j] = true;
            sum[i | 1 << j] = sum[i] + cnt[j];
        }
    }
    printf("%d\n", res);
    return 0;
}