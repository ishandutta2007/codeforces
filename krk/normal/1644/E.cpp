#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str); slen = strlen(str);
        int r = 0, c = 0;
        for (int i = 0; i < slen; i++)
            if (str[i] == 'D') r++;
            else c++;
        int dr = n - 1 - r, dc = n - 1 - c;
        bool hasR = false, hasD = false;
        r = c = 0;
        ll bad = 0;
        for (int i = 0; i < slen; i++)
            if (str[i] == 'D') {
                if (hasR) bad += max(0, n - 1 - c - dc);
                else bad += n - 1 - c;
                hasD = true;
                r++;
            } else {
                if (hasD) bad += max(0, n - 1 - r - dr);
                else bad += n - 1 - r;
                hasR = true;
                c++;
            }
        if (!hasR) bad += ll(n - r) * (n - 1 - c);
        if (!hasD) bad += ll(n - c) * (n - 1 - r);
        printf("%I64d\n", ll(n) * n - bad);
    }
    return 0;
}