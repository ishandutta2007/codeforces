#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
const int Maxm = Maxn * Maxn;

int T;
char s[Maxn];
int slen;
int my[Maxn][Maxn];

int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];

int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

int best[Maxm], blen;

bool Less(const int &a, const int &b) { return s[a] < s[b]; }

void buildSA()
{
    for (int i = 0; i < slen; i++)
        cur[i] = i;
    sort(cur, cur + slen, Less);
    for (int i = 0; i < slen; i++) {
        dif1[i] = i == 0 || s[cur[i - 1]] != s[cur[i]];
        dif2[i] = false;
    }
    for (int h = 1; h < slen; h <<= 1) {
        int buck = 0;
        for (int i = 0, j; i < slen; i = j) {
            j = i + 1;
            while (j < slen && !dif1[j]) j++;
            nxt[i] = j;
            buck++;
        }
        if (buck == slen) break;
        for (int i = 0; i < slen; i = nxt[i]) {
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; j++)
                rnk[cur[j]] = i;
        }
        cnt[rnk[slen - h]]++; dif2[rnk[slen - h]] = true;
        for (int i = 0; i < slen; i = nxt[i]) {
            for (int j = i; j < nxt[i]; j++) {
                int s = cur[j] - h;
                if (s >= 0) {
                    int head = rnk[s];
                    rnk[s] = head + cnt[head]++;
                    dif2[rnk[s]] = true;
                }
            }
            for (int j = i; j < nxt[i]; j++) {
                int s = cur[j] - h;
                if (s >= 0 && dif2[rnk[s]])
                    for (int k = rnk[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
            }
        }
        for (int i = 0; i < slen; i++) {
            cur[rnk[i]] = i;
            dif1[i] |= dif2[i];
        }
    }
}

void calcLCP()
{
    bef[cur[0]] = -1;
    for (int i = 1; i < slen; i++) bef[cur[i]] = cur[i - 1];
    int l = 0;
    for (int i = 0; i < slen; i++) if (bef[i] != -1) {
        while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l]) l++;
        plcp[i] = l;
        l = max(l - 1, 0);
    } else plcp[i] = 0;
    for (int i = 0; i < slen; i++)
        lcp[i] = plcp[cur[i]];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &slen);
        scanf("%s", s);
        buildSA();
        calcLCP();
        int pnt = 0;
        for (int i = 0; i < slen; i++)
            for (int j = lcp[i]; cur[i] + j < slen; j++) {
                my[cur[i]][cur[i] + j] = pnt;
                for (int z = i + 1; z < slen && lcp[z] > j; z++)
                    my[cur[z]][cur[z] + j] = pnt;
                pnt++;
            }
        blen = 0;
        for (int i = 0; i < slen; i++) {
            int st = 0;
            for (int j = i; j < slen; j++) {
                int ind = lower_bound(best + st, best + blen, my[i][j]) - best;
                if (ind < blen) best[ind] = my[i][j];
                else best[blen++] = my[i][j];
                st = ind + 1;
            }
        }
        printf("%d\n", blen);
    }
    return 0;
}