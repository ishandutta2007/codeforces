#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define MAXN 400013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
pii arr[MAXN];
vi xs, ys;
vi pos[MAXN];
int freq[MAXN];
ordered_set<int> cx;
ll ans;

int countrange(int l, int r)
{
	return cx.order_of_key(r + 1) - cx.order_of_key(l);
}
ll ch(ll x)
{
	return x * (x + 1) / 2;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i].fi >> arr[i].se;
		xs.PB(arr[i].fi);
		ys.PB(arr[i].se);
	}
	sort(arr, arr + N);
	sort(ALL(xs));
	xs.erase(unique(ALL(xs)), xs.end());
	sort(ALL(ys));
	ys.erase(unique(ALL(ys)), ys.end());
	FOR(i, 0, N)
	{
		arr[i].fi = LB(ALL(xs), arr[i].fi) - xs.begin();
		arr[i].se = LB(ALL(ys), arr[i].se) - ys.begin();
		pos[arr[i].se].PB(i);
		freq[arr[i].fi]++;
		cx.insert(arr[i].fi);
	}
	FOR(i, 0, SZ(ys))
	{
		for (int idx : pos[i])
		{
			freq[arr[idx].fi]--;
			cx.erase(arr[idx].fi);
		}
		int was = 0;
		vi num;
		for (int idx : pos[i])
		{
			num.PB(countrange(was, arr[idx].fi));
			was = arr[idx].fi;
		}
		num.PB(countrange(was, INF));
		// cerr << "SOLVE " << i << endl;
		ll sum = 0;
		for (ll x : num)
		{
			sum += x;
			sum++;
			ans -= ch(x);
			// cerr << "num " << x << endl;
		}
		ans += ch(sum - 1);
		for (int idx : pos[i])
		{
			if (freq[arr[idx].fi] != 0)
			{
				cx.insert(arr[idx].fi);
			}
		}
	}
	cout << ans << '\n';
	return 0;
	//something something something distinct x coordinates!
	//iterate over everything
}