#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int u, v, val1, val2;
}l[50010], Stack[210];
int f[210], n, m, top, G, S;

inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-')f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}

int Find(int x)
{
    if(f[x] == x) return f[x];
    return f[x] = Find(f[x]);
}

bool cmp(Node a, Node b)
{
    if(a.val1 == b.val1) return a.val2 < b.val2;
    return a.val1 < b.val1;
}

int main()
{
    n = read();
    m = read();
    G = read();
    S = read();
    for(int i = 1; i <= m; i ++)
        l[i].u = read(), l[i].v = read(), l[i].val1 = read(), l[i].val2 = read();
    sort(l + 1, l + m + 1, cmp);
    ll ans = 0x3f3f3f3f3f3f3f3fll;
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++) f[j] = j;
        Stack[++ top] = l[i];
        for(int j = top; j >= 2; j --)
            if(Stack[j].val2 < Stack[j - 1].val2) swap(Stack[j], Stack[j - 1]);
        int cnt = 0;
        for(int j = 1; j <= top; j ++)
        {
            int Now = Find(Stack[j].u);
            int To = Find(Stack[j].v);
            if(Now != To)
            {
                f[Now] = To;
                Stack[++ cnt] = Stack[j];
                if(cnt == n - 1) break;
            }
        }
        if(cnt == n - 1) ans = min(ans,(ll)G * l[i].val1 + (ll)S *Stack[cnt].val2);
        top = cnt;
    }
    if(ans == 0x3f3f3f3f3f3f3f3fll) printf("-1");
    else printf("%I64d", ans);

    return 0;
}