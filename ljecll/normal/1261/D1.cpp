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
#define MAXN 200013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
ll K;
ll arr[MAXN];
ll pwk[MAXN];
ll fact[MAXN], ifact[MAXN];
ll ans;
int M;

ll expo(ll a, ll e)
{
	if (e == 0) return 1;
	ll res = expo(a * a % INF, e >> 1);
	if (e & 1)
	{
		res *= a; res %= INF;
	}
	return res;
}
ll choose(ll a, ll b)
{
	return fact[a] * ifact[b] % INF * ifact[a - b] % INF;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> N >> K;
	FOR(i, 0, N)
	{
		cin >> arr[i];
	}
	pwk[0] = 1;
	FOR(i, 1, N + 1)
	{
		pwk[i] = pwk[i - 1] * (K - 2) % INF;
	}
	FOR(i, 0, N)
	{
		if (arr[i] == arr[(i == 0 ? N - 1 : i - 1)]) M++;
	}
	fact[0] = 1;
	FOR(i, 1, N + 1)
	{
		fact[i] = fact[i - 1] * i % INF;
	}
	ifact[N] = expo(fact[N], INF - 2);
	FORD(i, N, 0)
	{
		ifact[i] = ifact[i + 1] * (i + 1) % INF;
	}
	for (int i = 0; i * 2 <= (N - M + 1); i++)
	{
		//choose to get i correct on both sides.
		//so there's (N-M choose i) * (N - M - i choose i) * k^(n - M - 2i)
		ll gain = choose(N - M, i) * choose(N - M - i, i) % INF * pwk[N - M - 2 * i];
		ans += gain; ans %= INF;
		// cerr << i << " correct " << gain << endl;
	}
	ans *= expo(K, M); ans %= INF;
	// cerr << "TOTAL " << ans << endl;
	ans = expo(K, N) - ans;
	ans *= ((INF + 1) / 2);
	ans %= INF; if (ans < 0) ans += INF;
	cout << ans << '\n';
	//how many give the same # of correct answers.
}