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
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
int T[N << 2], a[N], b[N];
int val[N],n;
inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}
inline int max(int a, int b)
{
	if(a > b) return a;
	return b;
}
inline void add(int x,int v)
{
	while(x <= 2 * n)
	{
		val[x] += v;
		x += x & (-x);
	}
}
inline int sum(int x)
{
	int t = 0;
	while(x)
	{
		t += val[x];
		x -= x & (-x);
	}
	return t;
}
inline int cal(int x,int y)
{
	return sum(y) - sum(x -1);
}
void update(int l, int r, int rt, int x, int v)
{
	if(l == r)
	{
		T[rt] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) update(l, mid, ls, x, v);
	else update(mid + 1, r, rs, x, v);
	T[rt] = min(T[ls], T[rs]);
	return ;
}
int query(int l, int r, int rt, int x, int y)
{
	if(x <= l && r <= y) return T[rt];
	if(r < x || l > y) return 1 << 30;
	int mid = (l + r) >> 1;
	return min(query(l, mid, ls, x, y), query(mid + 1, r, rs, x, y));
}
int main()
{
	n = read();
	rep(i, 1, n)
		a[i] = read(), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	rep(i, 1, 2 * n) add(i, 1);
	rep(i, 1, n) update(1, 2 * n, 1, i, a[i]);
	rep(i, n + 1, 2 * n) update(1, 2 * n, 1, i, a[i - n]);
	ll ans = 0;
	int T = n, now = 1;
	while(T --)
	{
		int l = 1, r = n;
		while(l != r)
		{
			int mid = (l + r) >> 1;
			if(query(1, 2 * n, 1, now, now + mid - 1) > b[n - T]) l = mid + 1;
			else r = mid;
		}
		ans += cal(now, now + l - 1);
		now += l;
		now --;
		if(now > n) now -= n;
		update(1, 2 * n, 1, now, 1 << 30);
		update(1, 2 * n, 1, now + n, 1 << 30);
		add(now, -1);
		add(now + n, -1);
		now ++;
	}
	cout << ans << endl;
	return 0;
}