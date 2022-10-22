#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1100005;
const int Maxl = 26;

char str[Maxn];
int slen;
int pnt[Maxn][Maxl];
int pi[Maxn];
int q;
int tlen;

int Get(int ind, int let)
{
    if (pnt[ind][let] == -1)
        if (str[ind] - 'a' == let) pnt[ind][let] = ind + 1;
        else pnt[ind][let] = ind == 0? 0: Get(pi[ind - 1], let);
    return pnt[ind][let];
}

int main()
{
    scanf("%s", str);
    slen = strlen(str);
    fill((int*)pnt, (int*)pnt + Maxn * Maxl, -1);
    for (int i = 1; i < slen; i++)
        pi[i] = Get(pi[i - 1], str[i] - 'a');
    scanf("%d", &q);
    while (q--) {
        scanf("%s", str + slen);
        tlen = strlen(str + slen) + slen;
        for (int i = slen; i < tlen; i++) {
            int cur = pi[i - 1];
            while (cur >= slen && str[i] != str[cur])
                cur = pi[cur - 1];
            if (cur < slen) pi[i] = Get(cur, str[i] - 'a');
            else pi[i] = cur + 1;
            printf("%d%c", pi[i], i + 1 < tlen? ' ': '\n');
        }
    }
    return 0;
}