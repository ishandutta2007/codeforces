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
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
const int P = 29;
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define lc c[x][0]
#define rc c[x][1]
const int N = 7000005;
set<int> S[2];
int c[N][2], key[N], rt[2], tot, ans;
void modify(int x, int l, int r, int ql, int qr, int val)
{
    int mid = l + r >> 1;
    if (ql <= l && r <= qr) {key[x] = max(key[x], val); return;}
    if (ql <= mid) {if (!lc) lc = ++ tot; modify(lc, l, mid, ql, qr, val);}
    if (mid < qr) {if (!rc) rc = ++ tot; modify(rc, mid + 1, r, ql, qr, val);}
}
void query(int x,int l,int r,int p)
{
    int mid = l + r >> 1;
    ans = max(ans, key[x]);
    if (l == r) return;
    if (p <= mid) if (lc) query(lc, l, mid, p);
    if (mid < p) if (rc) query(rc, mid + 1, r, p);
}
void work(int f,int x,int y,int n)
{
    if (f) swap(x, y);
    if (S[f].find(x) != S[f].end()) {puts("0"); return;}
    ans = 0;
    query(rt[f], 1, n, x);
    modify(rt[f ^ 1], 1, n, ans + 1, y, x);
    S[f].insert(x);
    printf("%d\n", y - ans);
}
int main()
{
	int i,n,q;
    n = read();
    q = read();
    rt[0] = 1, rt[1] = 2, tot = 2;
    while (q --)
    {
        int x, y;
        char op;
        x = read();
        y = read();
        op = getchar();
        if (op == 'U') work(0, x, y, n); 
        else work(1, x, y, n);
    }
    
    return 0;
}