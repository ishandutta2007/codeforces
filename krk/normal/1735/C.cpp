#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxl = 26;

int T;
int n;
char str[Maxn];
int nxt[Maxl], prv[Maxl];
char res[Maxn];

bool Check(int a, int b)
{
    if (a == b || prv[b] != -1) return false;
    int len = 1;
    while (b != -1 && b != a) {
        b = nxt[b];
        len++;
    }
    return b == -1 || len == Maxl;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        fill(nxt, nxt + Maxl, -1);
        fill(prv, prv + Maxl, -1);
        for (int i = 0; i < n; i++) {
            int let = str[i] - 'a';
            if (nxt[let] == -1) {
                int cand = 0;
                while (!Check(let, cand)) cand++;
                nxt[let] = cand; prv[cand] = let;
            }
            res[i] = nxt[let] + 'a';
        }
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}