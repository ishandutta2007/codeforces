#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int tc;
char S[Maxn];
int slen;
char T[Maxn];
int tlen;
int nxt[Maxn][Maxl];

int Solve()
{
    int cur = 0, res = 1;
    for (int i = 0; i < tlen; i++) {
        int let = T[i] - 'a';
        if (nxt[0][let] >= slen) return -1;
        if (nxt[cur][let] >= slen) { res++; cur = 0; }
        cur = nxt[cur][let] + 1;
    }
    return res;
}

int main()
{
    scanf("%d", &tc);
    while (tc--) {
        scanf("%s", S); slen = strlen(S);
        scanf("%s", T); tlen = strlen(T);
        for (int j = 0; j < Maxl; j++)
            nxt[slen][j] = slen;
        for (int i = slen - 1; i >= 0; i--)
            for (int j = 0; j < Maxl; j++)
                nxt[i][j] = S[i] == 'a' + j? i: nxt[i + 1][j];
        printf("%d\n", Solve());
    }
    return 0;
}