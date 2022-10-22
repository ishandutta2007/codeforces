#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int q;
int n;
ll k;
char str[Maxn];
int cnt[Maxn];
char res[Maxn];
int rlen;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %I64d", &n, &k);
        scanf("%s", str);
        fill(cnt, cnt + n + 1, 0);
        int was = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '1') was++;
            else {
                int tk = min(ll(was), k);
                k -= tk; cnt[was - tk]++;
            }
        rlen = 0;
        while (cnt[0]--) res[rlen++] = '0';
        for (int i = 1; i <= was; i++) {
            res[rlen++] = '1';
            while (cnt[i]--) res[rlen++] = '0';
        }
        res[rlen] = '\0';
        printf("%s\n", res);
    }
    return 0;
}