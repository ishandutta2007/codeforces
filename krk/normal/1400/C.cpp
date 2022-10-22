#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
char str[Maxn];
int slen;
int x;
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        scanf("%d", &x);
        fill(res, res + slen, '1');
        for (int i = 0; i < slen; i++)
            if (str[i] == '0') {
                if (i - x >= 0) res[i - x] = '0';
                if (i + x < slen) res[i + x] = '0';
            }
        bool ok = true;
        for (int i = 0; i < slen; i++)
            if (str[i] == '1')
                if ((i - x < 0 || res[i - x] == '0') &&
                    (i + x >= slen || res[i + x] == '0'))
                    ok = false;
        if (ok) {
            res[slen] = '\0';
            printf("%s\n", res);
        } else printf("-1\n");
    }
    return 0;
}