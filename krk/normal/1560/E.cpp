#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 1000005;

int T;
char str[Maxn];
int slen;
char cand[Maxn];
int clen;
int curcand[Maxn];
int curclen;
int freq[Maxl];
char res[Maxl];
int rlen;

void constructCand()
{
    curclen = 0;
    for (int i = 0; i < clen; i++)
        if (freq[cand[i] - 'a'] > 0)
            curcand[curclen++] = cand[i];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        fill(freq, freq + Maxl, 0);
        rlen = 0;
        for (int i = slen - 1; i >= 0; i--)
            if (freq[str[i] - 'a']++ == 0) res[rlen++] = str[i];
        reverse(res, res + rlen);
        res[rlen] = '\0';
        bool fall = false;
        for (int i = 0; i < rlen; i++) {
            int ind = res[i] - 'a';
            if (freq[ind] % (i + 1)) { fall = true; break; }
            freq[ind] /= (i + 1);
        }
        if (fall) { printf("-1\n"); continue; }
        clen = 0;
        for (int i = 0; i < slen; i++)
            if (freq[str[i] - 'a'] == 0) break;
            else { cand[clen++] = str[i]; freq[str[i] - 'a']--; }
        cand[clen] = '\0';
        for (int i = 0; i < rlen; i++)
            freq[res[i] - 'a'] = 1;
        int pnt = 0;
        for (int i = 0; i < rlen; i++) {
            constructCand();
            for (int j = 0; j < curclen; j++)
                if (pnt >= slen || str[pnt] != curcand[j]) { fall = true; break; }
                else pnt++;
            freq[res[i] - 'a'] = 0;
        }
        if (fall) { printf("-1\n"); continue; }
        printf("%s %s\n", cand, res);
    }
    return 0;
}