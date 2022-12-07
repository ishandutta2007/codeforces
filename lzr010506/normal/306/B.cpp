#include <bits/stdc++.h>
#define N 2000010
using namespace std;

struct Node
{
    int l, r, i;
}a[N], b[N];
int n, M, m, ans, r;
bool c[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
bool cmp(Node a, Node b)
{
    if(a.l != b.l)
        return a.l < b.l;
    return a.r > b.r;
}

int main()
{
    n = read();
    m = read();
    for(int i = 1; i <= m; i ++)
    {
    	a[i].l = read();
    	a[i].r = read();
    	a[i].r = a[i].l + a[i].r - 1;
    	a[i].i = i;
    }
    sort(a + 1, a + 1 + m, cmp);

    r = a[1].r;
    for(int i = 2; i <= m; i ++)
        if(a[i].r <= r)
            c[i] = true;
        else r = a[i].r;
    r = 0;
    for(int i = 1; i <= m; i ++)
        if(!c[i])
            b[++ r] = a[i];

    M = m; 
    m = r; 
    memset(c, 0, sizeof(c));
    int l = 1; r = 2; 
    c[a[1].i] = true;
    while(l <= m)
    {
        while(r <= m && b[l].r + 1 >= b[r].l) r ++;
        r --;
        if(l == r) l ++, c[b[l].i] = 1, ans ++;
        else c[b[r].i] = 1, l = r, ans ++;
    }
    printf("%d\n", M - ans);
    for(int i = 1; i <= M; i ++)
        if(!c[i]) printf("%d ", i);
    return 0;
}