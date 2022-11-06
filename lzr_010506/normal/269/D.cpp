#include <bits/stdc++.h>
#define inf 1000000000
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 100005;
struct Wall
{
    int h,l,r;
    Wall(){}
    Wall(int _h,int _l,int _r):h(_h),l(_l),r(_r){}
    bool operator<(const Wall w)const
    {
        return h < w.h;
    }
}Wa[N];
struct Seg_Tree
{
    int l, r;
    int val, tag;
}T[N << 3];
int n, t;
int x[N << 1], cnt, dp[N];

inline int max(int a, int b)
{
	if(a < b) return b;
	return a;
}

inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void Bulid(int rt, int l, int r)
{
    T[rt].l = l;
    T[rt].r = r;
    T[rt].val = T[rt].tag = -1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Bulid(lson, l, mid);
    Bulid(rson, mid + 1, r);
}

void Push_Down(int rt)
{
    if(T[rt].tag != -1)
    {
        T[lson].tag = T[rson].tag = T[rt].tag;
        T[lson].val = T[rson].val = T[rt].tag;
        T[rt].tag = -1;
    }
}

void Push_Up(int rt)
{
    T[rt].val = max(T[lson].val, T[rson].val);
}

void Update(int rt,int l,int r,int id)
{
    if(T[rt].l == l && T[rt].r == r)
    {
        T[rt].val = T[rt].tag = id;
        return ;
    }
    Push_Down(rt);
    int mid = (T[rt].l + T[rt].r) >> 1;
    if(r <= mid) Update(lson, l, r, id);
    else if(l > mid) Update(rson, l, r, id);
    else
    {
        Update(lson, l, mid, id);
        Update(rson, mid + 1, r, id);
    }
    Push_Up(rt);
}

int Query(int rt,int l,int r)
{
    if(T[rt].l == l && T[rt].r == r)
        return T[rt].val;
    int mid = (T[rt].l + T[rt].r) >> 1;
    Push_Down(rt);
    if(r <= mid) return Query(lson, l, r);
    else if(l > mid) return Query(rson, l, r);
    else return max(Query(lson, l, mid), Query(rson, mid + 1, r));
}

void slove(int l, int r, int ID, int ll, int rr)
{
    if(l > r) return;
    int id = Query(1, l, r);
    if(id == -1)
    {
        Update(1, l, r, ID);
        dp[ID] = x[r + 1] - x[l];
        return;
    }
    int L = Wa[id].l;
    int R = Wa[id].r;
    if((L >= l || ll) && (R <= r || rr))
        dp[ID] = max(dp[ID], min(dp[id], x[min(R, r) + 1] - x[max(L, l)]));
    if(l < L) slove(l, L - 1, ID, ll, 0);
    if(r > R) slove(R + 1, r, ID, 0, rr);
}

int main()
{
    n = read();
    t = read();
    for(int i = 0; i < n; i ++)
    {
        int h,l,r;
        h = read();
        l = read();
        r = read();
        Wa[i] = Wall(h, l, r);
        x[i * 2] = l;
        x[i * 2 + 1] = r;
    }
    x[n * 2] = -inf;
    x[n * 2 + 1] = inf;
    sort(x, x + 2 * n + 2);
    cnt = unique(x, x + 2 * n + 2) - x;
    Wa[n ++] = Wall(0, -inf, inf);
    Wa[n ++] = Wall(t, -inf, inf);
    sort(Wa, Wa + n);
    for(int i = 0; i < n; i ++)
    {
        Wa[i].l = lower_bound(x, x + cnt, Wa[i].l) - x;
        Wa[i].r = lower_bound(x, x + cnt, Wa[i].r) - x - 1;
    }
    Bulid(1, 0, cnt - 1);
    for(int i = 0; i < n; i ++)
    {
        int l = Wa[i].l;
        int r = Wa[i].r;
        slove(l, r, i, 1, 1);
        Update(1, l, r, i);
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}