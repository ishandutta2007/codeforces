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
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

ll N;
ll arr[MAXN];
map<ll, int> mp;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N) cin >> arr[i];
	sort(arr, arr + N);
	FOR(i, 0, N)
	{
		mp[arr[i]]++;
	}
	ll bad = -1;
	for (auto it : mp)
	{
		if (it.se > 2)
		{
			cout << "cslnb\n";
			return 0;
		}
		if (it.se == 2)
		{
			if (bad != -1)
			{
				cout << "cslnb\n";
				return 0;
			}
			bad = it.fi;
		}
	}
	if (bad != -1 && mp[bad - 1] >= 1)
	{
		cout << "cslnb\n";
		return 0;
	}
	if (bad == 0)
	{
		cout << "cslnb\n";
		return 0;
	}
	//OK now this is a normal game
	bad = 0;
	FOR(i, 0, N)
	{
		bad += arr[i];
		bad -= i;
	}
	bad %= 2;
	cout << (bad == 0 ? "cslnb" : "sjfnb") << '\n';
	return 0;
	//check if there's at least one legal move!
}