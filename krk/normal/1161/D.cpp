#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int mod = 998244353;

char str[Maxn];
int slen;
int col1[Maxn], col2[Maxn];
int len1;
int res;

bool Color2(int d, int c);

bool Color1(int ind, int c)
{
    if (col1[ind] != 2) return col1[ind] == c;
    col1[ind] = c;
    if (str[ind] != '?')
        if (!Color2(ind, str[ind] == '0'? c: 1 - c))
            return false;
    if (ind >= slen - len1)
        if (!Color1(slen - len1 + slen - 1 - ind, c))
            return false;
    return true;
}

bool Color2(int ind, int c)
{
    if (col2[ind] != 2) return col2[ind] == c;
    col2[ind] = c;
    if (str[ind] != '?')
        if (!Color1(ind, str[ind] == '0'? c: 1 - c))
            return false;
    if (!Color2(slen - 1 - ind, c))
        return false;
    return true;
}

int Solve(int x)
{
    fill(col1, col1 + slen, 2);
    fill(col2, col2 + slen, 2);
    len1 = x;
    if (!Color2(0, 1)) return 0;
    for (int i = 0; i < slen - x; i++)
        if (!Color1(i, 0)) return 0;
    if (!Color1(slen - x, 1)) return 0;
    int res = 1;
    for (int i = 0; i < slen; i++) {
        if (col1[i] == 2) {
            res = 2ll * res % mod;
            if (!Color1(i, 0)) return 0;
        }
        if (col2[i] == 2) {
            res = 2ll * res % mod;
            if (!Color2(i, 0)) return 0;
        }
    }
    return res;
}

int main()
{
    scanf("%s", str);
    slen = strlen(str);
    for (int i = 1; i < slen; i++)
        res = (res + Solve(i)) % mod;
    printf("%d\n", res);
    return 0;
}