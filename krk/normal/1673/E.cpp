#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 20;
const int Maxk = 25;

int n, k;
int b[Maxn];
bool vals[Maxk][3];
bool res[Maxn];
char str[Maxn];
int slen;

bool C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return false;
    return (n & k) == k;
}

int getGood(int l, int r)
{
    int res = 0;
    if (l) res++;
    if (r + 1 < n) res++;
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < Maxk; i++)
        for (int z = 0; z < 3; z++)
            for (int j = k - z; j <= n; j++) {
                vals[i][z] ^= C(n - i, j);
             //   printf("C(%d, %d) = %d\n", n - i, j, C(n - i, j));
            }
            //printf("vals[%d] = %d\n", i, vals[i]);
    for (int i = 0; i < n; i++) {
        int my = b[i];
        if (vals[1 + getGood(i, i)][getGood(i, i)]) res[my] ^= true;
        for (int j = i + 1; j < n; j++) {
            if (b[j] >= Maxk) break;
            if (my > Maxn / (1 << b[j])) break;
            my *= (1 << b[j]);
            if (my >= Maxn) break;
            if (vals[j - i + 1 + getGood(i, j)][getGood(i, j)]) {
                res[my] ^= true;
            }
        }
    }
    int pnt = Maxn - 1;
    while (pnt > 0 && !res[pnt]) pnt--;
    while (pnt >= 0) {
        str[slen++] = int(res[pnt]) + '0';
        pnt--;
    }
    str[slen] = '\0';
    printf("%s\n", str);
    return 0;
}