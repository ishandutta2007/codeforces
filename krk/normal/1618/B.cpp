#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
char str[Maxn];
char big[4], nxt[4];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", big);
        str[0] = big[0];
        int pnt = 1;
        for (int i = 1; i < n - 2; i++) {
            str[pnt++] = big[1];
            scanf("%s", nxt);
            if (big[1] != nxt[0])
                str[pnt++] = nxt[0];
            big[0] = nxt[0];
            big[1] = nxt[1];
        }
        str[pnt++] = big[1];
        if (pnt < n) str[pnt++] = big[1];
        str[n] = '\0';
        printf("%s\n", str);
    }
    return 0;
}