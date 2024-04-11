#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;
const int Maxm = 500005;
const int Maxk = 34;
const int Maxb = 60;

struct row {
    ll mask[Maxk];
    ll wh[Maxk];
    void Apply(const row &oth) {
        for (int i = 0; i < Maxk; i++) {
            mask[i] ^= oth.mask[i];
            wh[i] ^= oth.wh[i];
        }
    }
    void setMask(int b) { mask[b / Maxb] |= 1ll << ll(b % Maxb); }
    void setWh(int b) { wh[b / Maxb] |= 1ll << ll(b % Maxb); }
    bool getMask(int b) { return bool(mask[b / Maxb] & 1ll << ll(b % Maxb)); }
    bool getWh(int b) { return bool(wh[b / Maxb] & 1ll << ll(b % Maxb)); }
};

int n, m;
row B[Maxn];
int qa[Maxm], qb[Maxm];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        B[i].setWh(i);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &qa[i], &qb[i]);
        qa[i]--; qb[i]--;
        B[qa[i]].setMask(qb[i]);
    }
    for (int j = 0; j < n; j++) {
        int i = j;
        int i2 = i;
        while (!B[i2].getMask(j)) i2++;
        if (i != i2) swap(B[i], B[i2]);
        for (i2++; i2 < n; i2++) if (B[i2].getMask(j))
            B[i2].Apply(B[i]);
        for (i2 = i - 1; i2 >= 0; i2--) if (B[i2].getMask(j))
            B[i2].Apply(B[i]);
    }
    for (int i = 0; i < m; i++)
        printf("%s\n", B[qb[i]].getWh(qa[i])? "NO": "YES");
    return 0;
}