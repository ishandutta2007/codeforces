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
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, W;
vl arr[MAXN];
multiset<ll> nums[MAXN];
vi incr[MAXN], decr[MAXN];
int lt[MAXN], rt[MAXN];
ll res[MAXN];
ll ans[MAXN], sum = 0;
//at time t, person x increases

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> W;
	FOR(i, 0, N)
	{
		ll x; cin >> x;
		FOR(j, 0, x)
		{
			ll y; cin >> y; arr[i].PB(y);
		}
	}
	FOR(i, 0, N)
	{
		nums[i].insert(-INF);
		res[i] = 0;
		int n = SZ(arr[i]);
		FOR(j, 0, n)
		{
			incr[j].PB(i);
		}
		FOR(j, W - n + 1, W)
		{
			decr[j].PB(i);
		}
	}
	FOR(i, 0, W)
	{
		for (int x : incr[i])
		{
			sum -= res[x];
			// cerr << *nums[x].rbegin() << endl;
			// cerr << "sum = " << sum << endl;
			nums[x].insert(arr[x][rt[x]]);
			rt[x]++;
			res[x] = *nums[x].rbegin();
			if (i < W - SZ(arr[x]) || i >= SZ(arr[x])) ckmax(res[x], 0);
			sum += res[x];
			// cerr << "sum = " << sum << endl;
		}
		// cerr << "sum = " << sum << endl;
		for (int x : decr[i])
		{
			sum -= res[x];
			nums[x].erase(nums[x].find(arr[x][lt[x]]));
			lt[x]++;
			res[x] = *nums[x].rbegin();
			if (i < W - SZ(arr[x]) || i >= SZ(arr[x])) ckmax(res[x], 0);
			sum += res[x];
		}
		// cerr << "SUM = " << sum << endl;
		ans[i] = sum;
	}
	// cerr << "HELLO\n";
	FOR(i, 0, W)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
	//store a list of events that happen?
}