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
#define MAXN 1000013

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
ll tmp[MAXN];
ll sum = 0;
vl primes;
ll ans = 2696969696969696969ll;

void gen()
{
	ll tmp = sum;
	for (ll i = 2; i * i <= sum; i++)
	{
		if (tmp % i) continue;
		while(tmp % i == 0)
		{
			tmp /= i;
		}
		primes.PB(i);
	}
	if (tmp != 1)
	{
		primes.PB(tmp);
	}
	return;
}
ll check(ll p)
{
	//move all the shit to be divisible by x.
	ll res = 0;
	FOR(i, 0, N)
	{
		tmp[i] = arr[i] % p;
		// cerr << tmp[i];
	}
	// cerr << endl;
	FOR(i, 1, N)
	{
		res += min(tmp[i - 1], p - tmp[i - 1]);
		tmp[i] += tmp[i - 1]; if (tmp[i] >= p) tmp[i] -= p;
	}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum == 1)
	{
		cout << "-1\n";
		return 0;
	}
	gen();
	for (ll p : primes)
	{
		// cerr << "CHECK " << p << endl;
		ckmin(ans, check(p));
	}
	cout << ans << '\n';
	return 0;
	//you only need primes
}