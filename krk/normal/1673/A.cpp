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
        scanf("%s", str);
        slen = strlen(str);
        int sum = 0;
        for (int i = 0; i < slen; i++)
            sum += str[i] - 'a' + 1;
        int alice = sum, bob = 0;
        if (slen % 2) {
            int mn = min(str[0] - 'a' + 1, str[slen - 1] - 'a' + 1);
            alice -= mn; bob += mn;
        }
        if (alice > bob) printf("Alice %d\n", alice - bob);
        else printf("Bob %d\n", bob - alice);
    }
    return 0;
}