#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxp = 320;

int n, q;
int P[Maxn];
int qtyp[Maxn], qa[Maxn], qb[Maxn];
int seq[Maxn], slen;
int id[Maxn], len[Maxn];
int tk[Maxn];
int tmp[Maxn], tlen;
int spec[Maxn];
int myq[Maxn], mylft[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i]);
    for (int i = 0; i < q; i++)
        scanf("%d %d %d", &qtyp[i], &qa[i], &qb[i]);
    int pnt = 0, quer = 0;
    for (int i = 0; i < q; i += Maxp) {
        pnt++;
        int lim = min(i + Maxp, q);
        slen = 0;
        for (int j = i; j < lim; j++)
            if (qtyp[j] == 1) spec[qa[j]] = spec[qb[j]] = pnt;
        for (int j = 1; j <= n; j++) if (tk[j] < pnt) {
            tlen = 0;
            int num = j;
            while (tk[num] < pnt) {
                tk[num] = pnt;
                tmp[tlen++] = num;
                num = P[num];
            }
            int st = 0;
            while (st < tlen && spec[tmp[st]] < pnt) st++;
            if (st >= tlen) {
                for (int z = 0; z < tlen; z++) {
                    seq[slen++] = tmp[z];
                    id[tmp[z]] = slen - 1;
                    len[tmp[z]] = tlen - z;
                }
                seq[slen++] = tmp[0];
            } else {
                int lst = 0;
                for (int z = 1; z <= tlen; z++) {
                    int ind = (st + z) % tlen;
                    if (spec[tmp[ind]] >= pnt) {
                        for (int k = lst + 1; k <= z; k++) {
                            int ind2 = (st + k) % tlen;
                            seq[slen++] = tmp[ind2];
                            id[tmp[ind2]] = slen - 1;
                            len[tmp[ind2]] = z - k;
                        }
                        lst = z;
                    }
                }
            }
        }
        for (int j = i; j < lim; j++)
            if (qtyp[j] == 1) swap(P[qa[j]], P[qb[j]]);
            else {
                quer++;
                int num = qa[j], lft = qb[j];
                while (lft > 0 && myq[num] < quer) {
                    myq[num] = quer;
                    mylft[num] = lft;
                    if (spec[num] >= pnt) {
                        lft--;
                        num = P[num];
                    } else {
                        int tknow = min(lft, len[num]);
                        num = seq[id[num] + tknow];
                        lft -= tknow;
                    }
                }
                if (lft > 0) {
                    lft %= (mylft[num] - lft);
                    while (lft > 0)
                        if (spec[num] >= pnt) {
                            lft--;
                            num = P[num];
                        } else {
                            int tknow = min(lft, len[num]);
                            num = seq[id[num] + tknow];
                            lft -= tknow;
                        }
                }
                printf("%d\n", num);
            }
    }
    return 0;
}