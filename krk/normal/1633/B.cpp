#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        int zers = 0, ones = 0;
        for (int i = 0; i < slen; i++)
            if (str[i] == '0') zers++;
            else ones++;
        int res = min(zers, ones);
        if (zers == ones) res--;
        printf("%d\n", res);
    }
    return 0;
}