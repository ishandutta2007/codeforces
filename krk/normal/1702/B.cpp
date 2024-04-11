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
        int res = 1;
        set <char> S;
        for (int i = 0; i < slen; i++) {
            S.insert(str[i]);
            if (S.size() > 3) {
                res++;
                S.clear();
                S.insert(str[i]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}