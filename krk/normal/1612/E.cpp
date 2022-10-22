#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int m[Maxn], k[Maxn];
int sum[Maxn];
ii seq[Maxn];
int slen;
ld best = -1;
int wth;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &m[i], &k[i]);
    for (int c = 1; c <= 20; c++) {
        fill(sum, sum + Maxn, 0);
        for (int i = 1; i <= n; i++)
            sum[m[i]] += min(c, k[i]);
        slen = 0;
        for (int i = 0; i < Maxn; i++) if (sum[i])
            seq[slen++] = ii(sum[i], i);
        sort(seq, seq + slen);
        int tot = 0;
        for (int i = 1; i <= slen && i <= c; i++)
            tot += seq[slen - i].first;
        if (ld(tot) / c > best) {
            best = ld(tot) / c;
            wth = c;
        }
    }
    slen = 0;
    int tot = 0;
    for (int i = 1; i <= slen && i <= 20; i++)
        tot += seq[slen - i].first;
    for (int i = 21; i <= slen; i++) {
        tot += seq[slen - i].first;
        if (ld(tot) / i > best) {
            best = ld(tot) / i;
            wth = i;
        }
    }
    fill(sum, sum + Maxn, 0);
    int c = wth;
    for (int i = 1; i <= n; i++)
        sum[m[i]] += min(c, k[i]);
    slen = 0;
    for (int i = 0; i < Maxn; i++) if (sum[i])
        seq[slen++] = ii(sum[i], i);
    sort(seq, seq + slen);
    printf("%d\n", c);
    for (int i = 1; i <= c; i++)
        printf("%d%c", seq[slen - i].second, i + 1 <= c? ' ': '\n');
    return 0;
}