#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

char str[Maxn];
int slen;
set <int> S[Maxl];
int q;

int main()
{
    scanf("%s", str);
    slen = strlen(str);
    for (int i = 0; i < slen; i++)
        S[str[i] - 'a'].insert(i);
    scanf("%d", &q);
    while (q--) {
        int typ, a;
        scanf("%d %d", &typ, &a); a--;
        if (typ == 1) {
            char let; scanf(" %c", &let);
            if (str[a] != let) {
                S[str[a] - 'a'].erase(a);
                str[a] = let;
                S[str[a] - 'a'].insert(a);
            }
        } else {
            int b; scanf("%d", &b); b--;
            int res = 0;
            for (int i = 0; i < Maxl; i++) {
                set <int>::iterator it = S[i].lower_bound(a);
                if (it != S[i].end() && *it <= b) res++;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}