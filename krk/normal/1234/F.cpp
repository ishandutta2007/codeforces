#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 20;

char str[Maxn];
int slen;
int mask[Maxn];
int bits[1 << Maxm];
int best[1 << Maxm];
int res;

int main()
{
    for (int i = 0; i < 1 << Maxm; i++)
        bits[i] = __builtin_popcount(i);
    scanf("%s", str);
    slen = strlen(str);
    int all = (1 << Maxm) - 1;
    for (int i = 0; i < slen; i++) {
        for (int j = i; j < slen; j++) {
            if (mask[i] & 1 << int(str[j] - 'a'))
                break;
            else mask[i] |= 1 << int(str[j] - 'a');
            best[all ^ mask[i]] = bits[mask[i]];
        }
    }
    for (int j = 0; j < Maxm; j++)
        for (int i = 0; i < 1 << Maxm; i++) if (i & 1 << j)
            best[i ^ 1 << j] = max(best[i ^ 1 << j], best[i]);
    for (int i = 0; i < slen; i++) {
        mask[i] = 0;
        for (int j = i; j < slen; j++) {
            if (mask[i] & 1 << int(str[j] - 'a'))
                break;
            else mask[i] |= 1 << int(str[j] - 'a');
            res = max(res, bits[mask[i]] + best[mask[i]]);
        }
    }
    printf("%d\n", res);
    return 0;
}