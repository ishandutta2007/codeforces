#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, m;
set <int> S[Maxn];
int res;

int F(int x)
{
    return S[x].empty() || *S[x].rbegin() < x;
}

int main()
{
    scanf("%d %d", &n, &m);
    res = n;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        res -= (F(a) + F(b));
        S[a].insert(b);
        S[b].insert(a);
        res += F(a) + F(b);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int typ, a, b; scanf("%d", &typ);
        if (typ == 1) {
            scanf("%d %d", &a, &b);
            res -= (F(a) + F(b));
            S[a].insert(b);
            S[b].insert(a);
            res += F(a) + F(b);
        } else if (typ == 2) {
            scanf("%d %d", &a, &b);            
            res -= (F(a) + F(b));
            S[a].erase(b);
            S[b].erase(a);
            res += F(a) + F(b);
        } else printf("%d\n", res);
    }
    return 0;
}