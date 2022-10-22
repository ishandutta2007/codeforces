#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, h;
int a[Maxn];
multiset <int> S;

int main()
{
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        S.insert(-a[i]);
        bool tk = true;
        int lft = h;
        for (multiset <int>::iterator it = S.begin(); it != S.end() && lft >= 0; it++) {
            if (tk) lft += *it;
            tk = !tk;
        }
        if (lft < 0) { printf("%d\n", i); return 0; }
    }
    printf("%d\n", n);
    return 0;
}