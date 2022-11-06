#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
const int N = 500010;  
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct edge  
{  
    int to, next;  
}g[N * 2];  
struct node  
{  
    int l, r, val, mark;  
}s[N * 4];  
int head[N], in[N], out[N], fa[N];  
int n, cnt, num;  
bool f;  
void insert(int v, int u)  
{  
    g[cnt].to = u;  
    g[cnt].next = head[v];  
    head[v] = cnt ++;  
}  
void dfs(int v, int father)  
{  
    in[v] = ++ num;  
    for(int i = head[v]; i != -1; i = g[i].next)  
    {  
        int u = g[i].to;  
        if(u != father)  
        {  
            fa[u] = v;  
            dfs(u, v);  
        }  
    }  
    out[v] = num;  
}  
void push_up(int rt)  
{  
    if(s[ls].val == 1 && s[rs].val == 1) s[rt].val = 1; 
    else s[rt].val = 0;  
}  
void push_down(int rt)  
{  
    if(s[rt].mark)  
    {  
        s[ls].val = s[rs].val = s[rt].mark;  
        s[ls].mark = s[rs].mark = s[rt].mark;  
        s[rt].mark = 0;  
    }  
}  
void build(int l, int r, int rt)  
{  
    s[rt].l = l, s[rt].r = r, s[rt].val = 0, s[rt].mark = 0;  
    if(l == r) return;  
    int mid = (l + r) >> 1;  
    build(l, mid, ls);  
    build(mid + 1, r, rs);  
}  
void update(int l, int r, int c, int rt)  
{  
    if(l == 0) return;  
    if(l <= s[rt].l && s[rt].r <= r)  
    {  
        if(s[rt].val == 0) f = true; 
        s[rt].val = c;  
        if(c == 1) s[rt].mark = c;  
        return;  
    }  
    push_down(rt);  
    int mid = (s[rt].l + s[rt].r) >> 1;  
    if(l <= mid) update(l, r, c, ls);  
    if(r > mid) update(l, r, c, rs);  
    push_up(rt);  
}  
void query(int l, int r, int rt)  
{  
    if(l <= s[rt].l && s[rt].r <= r)  
    {  
        if(s[rt].val == 0) f = true;
        return;  
    }  
    push_down(rt);  
    int mid = (s[rt].l + s[rt].r) >> 1;  
    if(l <= mid) query(l, r, ls);  
    if(r > mid) query(l, r, rs);  
}  
int main ()  
{  
    int a, b;  
    n = read();
    cnt = num = 0;  
    memset(head, -1, sizeof head);  
    rep(i, 1, n - 1)
    {  
        a = read();
        b = read();
        insert(a, b);  
        insert(b, a);  
    }  
    fa[1] = 0;  
    dfs(1, 0);  
    build(1, num, 1);  
    int m = read();
    while(m --)  
    {  
        int op = read();
        int b = read();
        if(op == 1)  
        {  
            f = false;  
            update(in[b], out[b], 1, 1);  
            if(f) update(in[fa[b]], in[fa[b]], 0, 1);  
        }  
        else if(op == 2) update(in[b], in[b], 0, 1);  
        else  
        {  
            f = false;  
            query(in[b], out[b], 1);  
            if(f) printf("0\n");  
            else printf("1\n");  
        }  
    }  
    return 0;  
}