#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;
set <char> S;

bool Solve()
{
    int hm = S.size();
    set <char> cur;
    for (int i = 0; i < hm; i++)
        cur.insert(str[i]);
    if (cur.size() != S.size()) return false;
    for (int i = hm; i < slen; i++)
        if (str[i] != str[i - hm]) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        S.clear();
        for (int i = 0; i < slen; i++)
            S.insert(str[i]);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}