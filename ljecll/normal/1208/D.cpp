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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
ll arr[MAXN];
ll fen[MAXN];
ll ans[MAXN];
set<ll> alive;

void update(int idx, ll v)
{
	for (int e = idx + 1; e <= N + 1; e += e & (-e)) fen[e] += v;
}
ll query(int idx)
{
	ll res = 0;
	for (int e = idx + 1; e; e -= e & (-e)) res += fen[e];
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i];
	}
	FOR(i, 1, N + 1)
	{
		update(i + 1, i);
		alive.insert(i);
	}
	FORD(i, N, 0)
	{
		ll lo = 1, hi = N;
		while(hi > lo)
		{
			ll mid = (lo + hi) >> 1;
			if (query(mid) >= arr[i]) hi = mid;
			else lo = mid + 1;
		}
		ans[i] = *alive.LB(lo);
		alive.erase(ans[i]);
		update(ans[i] + 1, -ans[i]);
	}
	FOR(i, 0, N)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}