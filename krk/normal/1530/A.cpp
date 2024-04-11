#include <bits/stdc++.h>
using namespace std;

char s[50];
int T;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int slen = strlen(s);
        int res = 0;
        for (int i = 0; i < slen; i++)
            res = max(res, s[i] - '0');
        printf("%d\n", res);
    }
    return 0;
}