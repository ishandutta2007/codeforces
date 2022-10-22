#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400004;

int t;
int n;
int p[Maxn];
int seq[Maxn], slen;
int a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        slen = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            if (i && p[i - 1] != p[i]) seq[slen++] = i;
        }
        seq[slen++] = n;
        a = b = c = 0;
        int ca = seq[0], cb, cc;
        int ind = upper_bound(seq, seq + slen, ca + ca) - seq;
        if (ind < slen) {
            cb = seq[ind] - ca;
            ind = upper_bound(seq, seq + slen, n / 2) - seq - 1;
            if (ind >= 0 && seq[ind] - ca - cb > ca) {
                cc = seq[ind] - ca - cb;
                a = ca; b = cb; c = cc;
            }
        }
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}