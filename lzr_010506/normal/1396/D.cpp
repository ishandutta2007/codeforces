#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
const int N = 40010;
const int mod = 1e9 + 7;
int n, k, l, x[N], y[N], z[N];
int nx, ny, cx[N], cy[N], py[N], le[N], ri[N];
int mul(int x,int y){
	return 1LL *x*y% mod;
}
map<int, int> M;
vi v[N];
set<int> S[N];
ll ss, ans;
int a[N], t[N], w[N], fl[N], fr[N];
 
void push_down(int l, int r, int rt)
{
	if(w[rt] >= 0)
	{
		int mid = l + r >> 1;
		w[ls] = w[rt], w[rs] = w[rt];
		fl[ls] = w[rt], fr[ls] = w[rt];
		fl[rs] = w[rt], fr[rs] = w[rt];
		t[ls] = 1LL * w[rt] * (py[mid] - py[l - 1]) % mod;
		t[rs] = 1LL * w[rt] * (py[r] - py[mid]) % mod;
		w[rt] = -1;
	}
}
 
void build(int l, int r, int rt)
{
	w[rt] = -1;
	fl[rt] = a[l], fr[rt] = a[r];
	if(l == r)
	{
		t[rt] = 1LL * a[l] * cy[l] % mod;
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	t[rt] = t[ls] + t[rs];
	if(t[rt] >= mod) t[rt] -= mod;
}
 
void modify(int l, int r, int rt, int L, int v)
{
	if(r < L || fl[rt] <= v) return;
	if(L <= l && v <= fr[rt])
	{
		w[rt] = v;
		fl[rt] = v;
		fr[rt] = v;
		t[rt] = 1LL * v * (py[r] - py[l - 1]) % mod;
		return;
	}
	int mid = l + r >> 1;
	push_down(l, r, rt);
	modify(l, mid, ls, L, v);
	modify(mid + 1, r, rs, L, v);
	fl[rt] = fl[ls];
	fr[rt] = fr[rs];
	t[rt] = t[ls] + t[rs];
	if(t[rt] >= mod) t[rt] -= mod;
}
//map<int,int>::iterator it;
//set<int>::iterator it1;
int main()
{
	n = read();
	k = read();
	l = read();
	rep(i, 1, n) x[i] = read(), y[i] = read(), z[i] = read();
	M[-1] = 1; M[l] = 1;
	rep(i, 1, n) M[x[i]] = 1;
	nx = -1;
	for(map<int,int>::iterator it = M.begin(); it != M.end(); it ++)
		(*it).Y = ++ nx, cx[nx] = (*it).X;
	rep(i, 1, n) x[i] = M[x[i]];
	M.clear();
	rrep(i, nx, 1) cx[i] -= cx[i - 1];
	M[-1] = 1, M[l] = 1;
	rep(i, 1, n) M[y[i]] = 1;
	ny = -1;
	for(map<int,int>::iterator it = M.begin(); it != M.end(); it ++)
		(*it).Y = ++ ny, py[ny] = (*it).X;
	rep(i, 1, ny) cy[i] = py[i] - py[i - 1];
	rep(i, 1, n) y[i] = M[y[i]];
	M.clear();
	rep(i, 1, n) v[x[i]].pb(i);
	rep(j, 1, nx)
	{
		ss = 0;
		rep(i, 1, k) S[i].clear(), S[i].insert(0), S[i].insert(ny);
		rep(i, j, nx - 1)
			rep0(p, sz(v[i]))
			{
				int e = v[i][p];
				auto it1 = S[z[e]].lower_bound(y[e]);
				if((*it1) == y[e]) le[e] = -1, ri[e] = -1;
				else ri[e] = (*it1), it1 --, le[e] = (*it1);
				S[z[e]].insert(y[e]);
			}
		rep(i, 1, ny - 1) a[i] = 0;
		rep(i, 1, k)
		{
			int o = 0;
			for(auto it1 : S[i])
			{
				if(it1 == 0) continue;
				a[o + 1] = max(a[o + 1], it1);
				o = it1;
			}
 
		}
		rep(i, 2, ny - 1) a[i] = max(a[i], a[i - 1]);
		rep(i, 1, ny - 1) a[i] = l - py[a[i]];
		build(1, ny - 1, 1);
		for(int i = nx; i > j;)
		{
			ss += 1LL * t[1] * cx[i] % mod;
			ss %= mod;
			i --;
			for(int o = v[i].size(); o --;)
			{
				int e = v[i][o];
				if(le[e] != -1) modify(1, ny - 1, 1, le[e] + 1, l - py[ri[e]]);
			}
			
		}
		ans += 1LL * ss * cx[j] % mod;
		ans %= mod;
	}
	printf("%d\n", ans);
	return 0;
}