#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 1234567, mod = 1000000009, base = 357;
int n, m;
pii a[maxn], b[maxn];
pii A[maxn], B[maxn];
int p[maxn], q[maxn];

pii sub(pii a, pii b)
{
	return mp(a.fi - b.fi, a.se - b.se);
}

int dot(pii a, pii b)
{
	return a.fi * b.se - a.se * b.fi;
}

int co(pii p[], pii ch[], int n)
{
	int dn = 0;
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		while (dn >= 2 && 
		 dot(sub(p[i], ch[dn]), 
		     sub(p[i], ch[dn - 1])) >= 0)
		{
			--dn;
		}
		ch[++dn] = p[i];
	}
	int tot = dn;
	for (int i = n - 1; i >= 1; --i)
	{
		while (tot >= 1 + dn && 
		 dot(sub(p[i], ch[tot]), 
		     sub(p[i], ch[tot - 1])) >= 0)
		{
			--tot;
		}
		ch[++tot] = p[i];
	}
	return tot - 1;
}

int power(int a, int b)
{
	if (!a) return 0;
	if (!b) return 1;
	int ret = power(a * a % mod, b / 2);
	if (b & 1) ret = (a * ret) % mod;
	return ret;
}

int inv(int a)
{
	return power(a, mod - 2);
}

void input()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	F1 (i, n) cin >> a[i].fi >> a[i].se;
	F1 (i, m) cin >> b[i].fi >> b[i].se;
}

void str(pii p[], int n, int s[])
{
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i)
		x = (x + p[i].fi) % mod;
	for (int i = 1; i <= n; ++i)
		y = (y + p[i].se) % mod;
	x = x * inv(n) % mod;
	y = y * inv(n) % mod;
	pii mid = mp(x, y);
	int cnt = 0;
	for (int i = 2; i <= n + 1; ++i)
	{
		
		int a = ((sub(p[i - 1], mid).fi % mod) + mod) % mod;
		int b = ((sub(p[i - 1], mid).se % mod) + mod) % mod;
		int c = ((sub(p[i], mid).fi % mod) + mod) % mod;
		int d = ((sub(p[i], mid).se % mod) + mod) % mod;
		
		s[++cnt] = ((a * a % mod) + (b * b % mod)) % mod;
		s[++cnt] = (((a * c % mod) + (b * d % mod)) % mod) * inv((c * c % mod) + (d * d % mod)) % mod;
		s[++cnt] = ((((mod - a) * d % mod) + (b * c % mod)) % mod) * inv((c * c % mod) + (d * d % mod)) % mod; 
	}
}

void solve()
{
	int sa = co(a, A, n);
	int sb = co(b, B, m);
	
	//F1 (i, sa) dbgg(A[i]);
	//F1 (i, sa) dbgg(B[i]);
	//MEOW
	
	if (sa != sb) { cout << "NO\n"; return; }
	str(A, sa, p);
	str(B, sb, q);
	
	//F1 (i, 3*sa) dbg(p[i]);
	//MEOW
	//F1 (i, 3*sa) dbg(q[i]);
	
	for (int i = 1; i <= 3 * sa; ++i)
	{
		p[3 * sa + i] = p[i];
	}
	int ha = 0, hb = 0;
	for (int i = 1; i <= sa * 3; ++i)
	{
		ha = (ha * base) % mod;
		ha = (ha + p[i]) % mod;
	}
	for (int i = 1; i <= sa * 3; ++i)
	{
		hb = (hb * base) % mod;
		hb = (hb + q[i]) % mod;
	}
	int tran = power(base, sa * 3 - 1);
	if (ha == hb) { cout << "YES\n"; return; }
	for (int cur = 3 * sa + 1; cur <= 6 * sa; ++cur)
	{
		ha = (ha - (tran * p[cur - 3 * sa] % mod) + mod) % mod;
		ha = (ha * base) % mod;
		ha = (ha + p[cur]) % mod;
		if (ha == hb) { cout << "YES\n"; return; }
	}
	
	cout << "NO\n";
}

main()
{
	input();
	solve();
}