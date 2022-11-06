#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 1e5 + 10;

int n, K, lst[N], pre[N], a[N], dp[N];
int T[N * 4], tag[N * 4];

void Build(int rt,int l,int r)
{
    if (l == r) {T[rt] = dp[l]; return;}
    int mid = (l + r) >> 1;
    Build(ls, l, mid);
    Build(rs, mid + 1, r);
    T[rt] = max(T[ls], T[rs]);
    tag[rt] = 0;
}

void update(int rt,int l,int r,int val)
{
    T[rt] += val;
    if (l < r) tag[rt] += val;
}

void pushdown(int rt,int l,int r)
{
    int mid = (l + r) >> 1;
    if (l < r) 
    	update(ls, l, mid, tag[rt]),
    	update(rs, mid + 1, r, tag[rt]);
    tag[rt] = 0;
}

void add(int rt,int l,int r,int x,int y,int val)
{
    if (x <= l && r <= y) {update(rt, l, r, val); return;}
   	if (tag[rt]) pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) add(ls, l, mid, x, y, val);
    if (y > mid) add(rs, mid + 1, r, x, y, val); 
    T[rt] = max(T[ls], T[rs]);
}

int query(int rt,int l,int r,int x,int y)
{
   	if (x <= l && r <= y) return T[rt];
    if (tag[rt]) pushdown(rt,l,r);
    int mid = (l + r) >> 1, ans = 0;
    if (x <= mid) ans = max(ans, query(ls, l, mid, x, y));
    if (y > mid) ans = max(ans, query(rs, mid + 1, r, x, y));
    T[rt] = max(T[ls], T[rs]);
    return ans;
}

int main()
{
    n = read();
    K = read();
    rep(i, 1, n)
    {
    	a[i] = read();
        pre[i] = lst[a[i]];
        lst[a[i]] = i;
    }

    rep(que, 1, K)
    {
        dp[0] = 0;
        rep(i, 1, n)
        {
            add(1, 0, n, pre[i], i - 1, 1);
            if (i < que) {dp[i] = 0; continue;}
            dp[i] = query(1, 0, n, que - 1, i - 1);
        }
        Build(1, 0, n);
    }

    printf("%d\n",dp[n]);

    // system("pause");
    return 0;
}