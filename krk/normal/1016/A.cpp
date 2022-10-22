#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    ll lst = 0;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        ll nw = lst + a;
        printf("%I64d%c", nw / m - lst / m, i + 1 <= n? ' ': '\n');
        lst = nw;
    }
    return 0;
}