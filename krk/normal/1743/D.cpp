#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
char str[Maxn];
int pnt, hl;
int nd[Maxn], nlen;
int seq[Maxn], slen;

bool Better(const int &a, const int &b)
{
    for (int i = 0; i < nlen; i++) {
        char vala = str[a + nd[i]], valb = str[b + nd[i]];
        if (vala != valb) return vala > valb;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    while (pnt < n && str[pnt] == '0') pnt++;
    hl = pnt;
    while (hl < n && str[hl] == '1') hl++;
    if (hl < n) nd[nlen++] = 0;
    for (int i = hl + 1; i < n; i++)
        if (str[i] == '0') nd[nlen++] = i - hl;
    int best = pnt;
    for (int i = pnt + 1; i < hl; i++)
        if (Better(i, best)) best = i;
    for (int i = nlen - 1; i >= 0; i--)
        if (str[best + nd[i]] == '1')
            str[hl + nd[i]] = '1';
    if (pnt >= n) printf("0\n");
    else printf("%s\n", str + pnt);
    return 0;
}