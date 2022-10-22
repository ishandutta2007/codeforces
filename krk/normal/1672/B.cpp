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
        int st = 0;
        bool fall = str[slen - 1] != 'B';
        for (int i = 0; i < slen; i++) {
            st += str[i] == 'A'? 1: -1;
            if (st < 0) fall = true;
        }
        printf("%s\n", fall? "NO": "YES");
    }
    return 0;
}