#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define E Maxke_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).sze()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
const int P = 29;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;

int n, m, i, h, x, ans, h1;
int a[N], K[N], id[N], st[4 * N] ,size[4 * N];

void update(int rt,int l,int r,int x,bool w)
{
	if(l > x || r < x) return;
	if(l == r)
	{
		if(w == 1) 
		{
			size[rt] = 1;
			st[rt] = a[x];
			return;
		}
		size[rt] --;
		st[rt] = 0;
		return;
	}
	int mid = l + r >> 1;
	update(ls, l, mid, x, w);
	update(rs, mid + 1, r, x, w);
	size[rt] = size[ls] + size[rs];
	st[rt] = ((ll)st[ls] * K[size[rs]] % mod + st[rs]) % mod;
}

int main()
{
	n = read();
	m = read();
	
	K[0] = 1;
	rep(i, 1, n)
		K[i] = (ll)K[i - 1] * P % mod;

	rep(i, 1, n)
	{
		x = read();
		h = ((ll)h * P % mod + x) % mod;
		h1 = ((ll)h1 * P % mod + 1) % mod;
	}

	rep(i, 1, m)
	{
		a[i] = read();
		id[a[i]] = i;
		if(a[i] <= n) update(1, 1, m, i, 1);
	}

	rep(i, 1, m - n + 1)
	{
		if(st[1] == (h + (ll)(i - 1) * h1 % mod) % mod)	ans ++;
		update(1, 1, m, id[i], 0);
		update(1, 1, m, id[n + i], 1);
	}
	if(st[1] == h) ans ++;
	printf("%d",ans);
	return 0;
}