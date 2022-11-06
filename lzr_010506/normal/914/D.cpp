#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int t[30000010], opt, n, q;
int gcd(int a,int b)
{
	while(a)
	{
		int c = a;
		a = b % a;
		b = c;
	}
	return b;
}
void build(int rt, int l, int r)
{
    if(l == r)
    {
        t[rt] = read();
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    t[rt] = gcd(t[ls], t[rs]);
}
void insert(int rt,int l,int r,int x,int y)
{
    if(l == r)
    {
        t[rt] = y;
        return;
    }
    int mid = l + r >> 1;
    if(x <= mid) insert(ls, l, mid, x, y);
    else insert(rs, mid + 1, r, x, y);
    t[rt] = gcd(t[ls], t[rs]);
}
int query(int way, int rt, int l, int rr, int r, int x)
{
    int mid = (l + rr) >> 1;
    if (way == 1)
    {
        if(rr <= r)
        {
            if(l == rr)
            {
                if (t[rt] % x == 0) return rr;
                else return rr + 1;
            }
            if(t[rs] % x == 0)return query(1, ls, l, mid, r, x);
            else return query(1, rs, mid + 1, rr, r, x);
        }
        if(r <= mid) return query(1, ls, l, mid, r, x);
        else
        {
            int tmp = query(1, rs, mid + 1, rr, r, x);
            if(tmp == mid + 1) return query(1, ls, l, mid, r, x);
            else return tmp;
        }
    }
    else
    {
        if(l >= r)
        {
            if(l == rr)
            {
                if (t[rt] % x == 0) return l;
                else return l - 1;
            }
            if(t[ls] % x == 0) return query(2, rs, mid + 1, rr, r, x);
            else return query(2, ls, l, mid, r, x);
        }
        if(r > mid) return query(2, rs, mid + 1, rr, r, x);
        else
        {
            int tmp = query(2, ls, l, mid, r, x);
            if(tmp == mid) return query(2, rs, mid + 1, rr, r, x);
            else return tmp;
        }
    }
}

int main()
{
	n = read();
	build(1, 1, n);
	q = read();
	rep(i, 1, q)
	{
        int op,l,r,x,y;
        op = read();
        if(op == 1)
        {
        	l = read();
        	r = read();
        	x = read();
            int t1 = query(2,1,1,n,l,x);
            int t2 = query(1,1,1,n,r,x);
            if (t2 - t1 <= 2) puts("YES");
            else puts("NO");
        }
        else
        {
        	x = read();
        	y = read();
            insert(1, 1, n, x, y);
        }
    }
    return 0;
}