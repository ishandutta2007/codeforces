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
#define MAXN 300013
#define CO 1000007
#define INF 1000000931
#define MOD 1000000933

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

void normalize(ll &x, ll mod)
{
	x %= mod; if (x < 0) x += mod;
}

int N, TC;
vi arr;
pll pw[MAXN];
ll ans;

void solve(int L, int R)
{
	if (L == R) return;
	// cerr << "SOLVE " << L << ' ' << R << endl;
	int mid = (L + R) >> 1;
	//store hashes of the stack?
	vpl lt, rt;
	vi st;
	pll hsh = {0, 0};
	FORD(i, mid + 1, L)
	{
		int x = arr[i];
		if (!st.empty() && st.back() == x)
		{
			hsh.fi -= 1ll * x * pw[SZ(st) - 1].fi; normalize(hsh.fi, INF);
			hsh.se -= 1ll * x * pw[SZ(st) - 1].se; normalize(hsh.se, MOD);
			st.pop_back();
		}
		else
		{
			st.PB(x);
			hsh.fi += 1ll * x * pw[SZ(st) - 1].fi; normalize(hsh.fi, INF);
			hsh.se += 1ll * x * pw[SZ(st) - 1].se; normalize(hsh.se, MOD);
		}
		lt.PB(hsh);
	}
	st.clear();
	hsh = {0, 0};
	//this time we need to store hashes in reverse order
	FOR(i, mid + 1, R + 1)
	{
		int x = arr[i];
		if (!st.empty() && st.back() == x)
		{
			hsh.fi -= 1ll * x * pw[SZ(st) - 1].fi; normalize(hsh.fi, INF);
			hsh.se -= 1ll * x * pw[SZ(st) - 1].se; normalize(hsh.se, MOD);
			st.pop_back();
		}
		else
		{
			st.PB(x);
			hsh.fi += 1ll * x * pw[SZ(st) - 1].fi; normalize(hsh.fi, INF);
			hsh.se += 1ll * x * pw[SZ(st) - 1].se; normalize(hsh.se, MOD);
		}
		rt.PB(hsh);
	}
	// cerr << "ALIVE\n";
	// if (L == 0 && R == 4)
	// {
	// 	for (pll p : lt)
	// 	{
	// 		cerr << p.fi << ' ';
	// 	}
	// 	cerr << endl;
	// 	for (pll p : rt)
	// 	{
	// 		cerr << p.fi << ' ';
	// 	}
	// 	cerr << endl;
	// }
	sort(ALL(rt));
	ll res = 0;
	for (pll p : lt)
	{
		res += (UB(ALL(rt), p) - LB(ALL(rt), p));
	}
	ans += res;
	// cerr << L << " <- " << mid << " -> " << R << ' ' << res << endl;
	//ok work!
	solve(L, mid);
	solve(mid + 1, R);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	while(TC--)
	{
		ans = 0;
		cin >> N;
		arr.resize(N);
		FOR(i, 0, N) cin >> arr[i];
		pw[0] = {1, 1};
		FOR(i, 1, N + 2)
		{
			pw[i].fi = pw[i - 1].fi * CO % INF;
			pw[i].se = pw[i - 1].se * CO % MOD;
		}
		solve(0, N - 1);
		cout << ans << '\n';
	}
	return 0;
}