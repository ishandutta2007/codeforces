#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        int res = 0;
        for (int i = 0; i < slen; i++)
            if (str[i] == '0' && (i == 0 || str[i - 1] == '1')) res++;
        printf("%d\n", min(res, 2));
    }
    return 0;
}