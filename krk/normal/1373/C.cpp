#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int T;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int lst = 0;
        ll res = 0;
        scanf("%s", str);
        int slen = strlen(str);
        int st = 0;
        for (int i = 0; i < slen; i++) {
            if (str[i] == '+') st--;
            else st++;
            if (st > lst) {
                res += ll(i + 1) * (st - lst);
                lst = st;
            }
        }
        res += slen;
        printf("%I64d\n", res);
    }
    return 0;
}