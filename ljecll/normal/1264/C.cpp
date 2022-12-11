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
#define MAXN 200013
#define INF 998244353

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

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

int N, Q;
ll INV;
ll prob[MAXN], iprob[MAXN];
ll psum[MAXN], prod[MAXN], iprod[MAXN];
set<int> guys;
ll ans;

ll getval(int L, int R)
{
	ll res = psum[L] - psum[R + 1];
	res *= iprod[R + 1]; res %= INF;
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> N >> Q;
	INV = expo(100, INF - 2);
	FOR(i, 0, N)
	{
		cin >> prob[i];
		prob[i] *= INV;
		prob[i] %= INF;
		iprob[i] = expo(prob[i], INF - 2);
	}
	prod[N] = 1;
	iprod[N] = 1;
	psum[N] = 0;
	FORD(i, N, 0)
	{
		prod[i] = prod[i + 1] * iprob[i];
		prod[i] %= INF;
		iprod[i] = iprod[i + 1] * prob[i];
		iprod[i] %= INF;
		psum[i] = psum[i + 1] + prod[i];
		if (psum[i] >= INF) psum[i] -= INF;
	}
	ans = getval(0, N - 1);
	guys.insert(0);
	guys.insert(N);
	while(Q--)
	{
		int u;
		cin >> u;
		u--;
		if (guys.find(u) == guys.end())
		{
			auto it = guys.LB(u);
			int lt = *prev(it), rt = *it;
			ans -= getval(lt, rt - 1);
			ans += getval(lt, u - 1);
			ans += getval(u, rt - 1);
			ans %= INF; if (ans < 0) ans += INF;
			guys.insert(u);
		}
		else
		{
			guys.erase(u);
			auto it = guys.LB(u);
			int lt = *prev(it), rt = *it;
			ans -= getval(lt, u - 1);
			ans -= getval(u, rt - 1);
			ans += getval(lt, rt - 1);
			ans %= INF; if (ans < 0) ans += INF;
		}
		cout << ans << '\n';
	}
	return 0;
	//store a suffix product.
}