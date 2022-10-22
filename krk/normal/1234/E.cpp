#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
int X[Maxn];
ll upd[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &X[i]);
    for (int i = 1; i < m; i++) {
        int a = X[i - 1], b = X[i];
        if (a > b) swap(a, b);
        if (a == b) continue;
        // 1..a-1
        upd[1] += b - a;
        upd[a] -= (b - a);
        // a
        upd[a] += b - 1;
        upd[a + 1] -= (b - 1);
        // a+1..b-1
        if (a + 1 < b) {
            upd[a + 1] += b - a - 1;
            upd[b] -= (b - a - 1);
        }
        // b
        upd[b] += a;
        upd[b + 1] -= a;
        // b+1, n
        upd[b + 1] += b - a;
        upd[n + 1] -= (b - a);
    }
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += upd[i];
        printf("%I64d%c", cur, i + 1 <= n? ' ': '\n');
    }
    return 0;
}