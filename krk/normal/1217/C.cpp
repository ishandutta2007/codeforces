#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxb = 20;

int T;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int slen = strlen(str);
        int res = 0;
        for (int i = 0; i < slen; i++) if (str[i] == '1') {
            int prv = 0;
            while (i - prv - 1 >= 0 && str[i - prv - 1] != '1') prv++;
            int cur = 0;
            for (int j = i; j < slen && j < i + Maxb; j++) {
                cur = 2 * cur + int(str[j] == '1');
                if (j - i + 1 <= cur && cur <= j - i + 1 + prv) res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}