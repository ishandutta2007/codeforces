#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 5100000;
const int Maxk = 8;
const int Maxs = 15;

int prime[Maxm], plen;
int mn[Maxm];
int n, q;
ii best[Maxm][Maxk];
int blen[Maxm];
int seq[Maxk], slen;
int mx[Maxs][Maxn];

void Insert(int lvl, int key, int val, int ind)
{
    if (lvl >= slen) {
        while (blen[key] > 0 && best[key][blen[key] - 1].first >= val)
            blen[key]--;
        best[key][blen[key]++] = ii(val, ind);
    } else {
        Insert(lvl + 1, key * seq[lvl], val, ind);
        Insert(lvl + 1, key, val + 1, ind);
    }
}

void Get(int lvl, int key, int val, int ind)
{
    if (lvl >= slen)
        for (int i = 0; i < blen[key]; i++)
            mx[val + best[key][i].first][ind] = max(mx[val + best[key][i].first][ind], best[key][i].second);
    else {
        Get(lvl + 1, key * seq[lvl], val, ind);
        Get(lvl + 1, key, val + 1, ind);
    }
}

int main()
{
    for (int i = 2; i < Maxm; i++) {
        if (mn[i] == 0) {
            prime[plen++] = i;
            mn[i] = i;
        }
        for (int j = 0; j < plen && i * prime[j] < Maxm; j++) {
            mn[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        slen = 0;
        while (a > 1) {
            int cnt = 0;
            int cur = mn[a];
            while (cur == mn[a]) {
                cnt++;
                a /= cur;
            }
            if (cnt % 2) seq[slen++] = cur;
        }
        for (int j = 0; j < Maxs; j++)
            mx[j][i] = mx[j][i - 1];
        Get(0, 1, 0, i);
        Insert(0, 1, 0, i);
    }
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        int res = 0;
        while (mx[res][r] < l) res++;
        printf("%d\n", res);
    }
    return 0;
}