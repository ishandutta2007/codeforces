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
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define MAXM 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

ll N, M, K;
ll arr[MAXM];
ll ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	//ok so a new page starts if the # of guys is >= k
	FOR(i, 0, M)
	{
		cin >> arr[i]; arr[i]--;
	}
	//holy shit what the
	//we'll store how many people are "alive" up to x
	ll alive = 0, was = -1, active = 0;
	FOR(i, 0, M)
	{
		alive += (arr[i] - was);
		// cerr << alive << endl;
		//new page if # of alive people is > K and there's at least one active person
		if (alive > K)
		{
			if (active)
			{
				ans++;
			}
			alive -= active;
			active = 0;
			alive %= K;
			if (alive == 0) alive = K;
		}
		// cerr << "a " << alive << endl;
		was = arr[i];
		active++;
	}
	if (active) ans++;
	// ans--;
	cout << ans << '\n';
	return 0;
}