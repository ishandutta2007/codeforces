#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxk = 450;

char str[Maxn];
int slen;
int o[Maxn];
int lef[Maxn], rig[Maxn];
int cnt[(Maxk + 1) * Maxn];
ll res;

int main()
{
    scanf("%s", str + 1);
    slen = strlen(str + 1);
    for (int i = 0; i <= slen; i++)
        lef[i] = Maxn;
    for (int i = 1; i <= slen; i++) {
        o[i] = o[i - 1] + (str[i] == '1');
        lef[o[i]] = min(lef[o[i]], i);
        rig[o[i]] = i;
    }
    for (int k = 1; k < Maxk; k++) {
        for (int i = 0; i <= slen; i++)
            res += cnt[ll(k) * o[i] - i + Maxn]++;
        for (int i = 0; i <= slen; i++)
            cnt[ll(k) * o[i] - i + Maxn] = 0;
    }
    for (int i = 0; i <= slen; i++)
        for (int j = 1; j <= Maxk && o[i] + j <= o[slen]; j++) {
            int L = max(lef[o[i] + j], i + j * Maxk);
            if (i % j != L % j) L += (i % j - L % j + j) % j;
            int R = rig[o[i] + j];
            if (L <= R) res += 1 + (R - L) / j;
        }
    printf("%I64d\n", res);
    return 0;
}