#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 998244353
#define MAXN 33013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, K, Q;
vl arr, tmp;
ll root = 3;
vl roots;
vl seg[MAXN << 1];
ll ans;

ll expo(ll a, ll e)
{
	if (e == 0) return 1;
	if (e & 1) return expo(a * a % INF, e >> 1) * a % INF;
	return expo(a * a % INF, e >> 1);
}
void init(int deg)
{
	roots.resize(deg);
	roots[0] = 1;
	roots[1] = expo(root, (INF - 1) / deg);
	FOR(i, 2, deg)
	{
		roots[i] = roots[i - 1] * roots[1] % INF;
	}
	return;
}
void ntt(vl &f)
{
	int deg = SZ(f);
	vl g(deg);
	for (int i = deg >> 1; i; i >>= 1)
	{
		for (int j = 0; j < deg; j += i)
		{
			int t = (2 * j >= deg ? 2 * j - deg : 2 * j);
			FOR(k, 0, i)
			{
				g[j + k] = f[t + k] + roots[j] * f[t + k + i]; g[j + k] %= INF;
			}
		}
		swap(f, g);
	}
	return;
}
vl poly_mult(vl a, vl b)
{
	int siz = SZ(a) + SZ(b) - 1, siz1 = (1 << (32 - __builtin_clz(siz)));
	if (SZ(a) * SZ(b) <= 100)
	{
		vl res(siz);
		FOR(i, 0, SZ(a))
		{
			FOR(j, 0, SZ(b))
			{
				res[i + j] += a[i] * b[j];
				res[i + j] %= INF;
			}
		}
		return res;
	}
	a.resize(siz1); b.resize(siz1); init(siz1);
	ntt(a); ntt(b);
	ll isiz = expo(siz1, INF - 2);
	FOR(i, 0, siz1)
	{
		a[i] *= b[i]; a[i] %= INF;
	}
	ntt(a);
	FOR(i, 0, siz1)
	{
		a[i] *= isiz; a[i] %= INF;
	}
	reverse(a.begin() + 1, a.end());
	a.resize(siz);
	return a;
}

void poly_debug(vl f, int d)
{
	for (int i = d; i >= 0; i--)
	{
		cerr << "(" << f[i] << ")x^" << i;
		if (i)
		{
			cerr << '+';
		}
		else
		{
			cerr << endl;
		}
	}
	return;
}
void build(int w, int L, int R)
{
	if (L == R)
	{
		seg[w].resize(2);
		seg[w][1] = 1;
		seg[w][0] = -arr[L]; seg[w][0] %= INF; if (seg[w][0] < 0) seg[w][0] += INF;
		// cerr << L << endl;
		// poly_debug(seg[w], SZ(seg[w]) - 1);
		return;
	}
	int mid = (L + R) >> 1;
	build(w << 1, L, mid);
	build(w << 1 | 1, mid + 1, R);
	seg[w] = poly_mult(seg[w << 1], seg[w << 1 | 1]);
	// cerr << L << ' ' << R << endl;
	// poly_debug(seg[w], SZ(seg[w]) - 1);
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	FOR(i, 0, N)
	{
		int x; cin >> x; tmp.PB(x);
	}
	cin >> Q;
	while(Q--)
	{
		arr = tmp;
		int qid; cin >> qid;
		if (qid == 1)
		{
			ll q, d; int i;
			cin >> q >> i >> d; i--;
			arr[i] = d;
			FOR(j, 0, N)
			{
				arr[j] = q - arr[j];
			}
		}
		if (qid == 2)
		{
			ll q, d; int l, r;
			cin >> q >> l >> r >> d; l--; r--;
			FOR(i, l, r + 1)
			{
				arr[i] += d;
			}
			FOR(j, 0, N)
			{
				arr[j] = q - arr[j];
			}
		}
		build(1, 0, N - 1);
		ans = seg[1][N - K];
		if (K & 1) ans = -ans;
		if (ans < 0) ans += INF;
		cout << ans << '\n';
	}
	return 0;
}