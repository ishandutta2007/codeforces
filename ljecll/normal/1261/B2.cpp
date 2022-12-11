#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int N, Q;
int arr[MAXN];
int ord[MAXN];
vpi query[MAXN];
ordered_set<int> lis;
int ans[MAXN];

bool cmp(int a, int b)
{
	if (arr[a] != arr[b])
	{
		return arr[a] > arr[b];
	}
	return a < b;
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
		ord[i] = i;
	}
	sort(ord, ord + N, cmp);
	cin >> Q;
	FOR(i, 0, Q)
	{
		int k, idx;
		cin >> k >> idx; k--; idx--;
		query[k].PB({idx, i});
	}
	FOR(i, 0, N)
	{
		lis.insert(ord[i]);
		for (pii p : query[i])
		{
			int qid = p.se, idx = p.fi;
			ans[qid] = arr[*lis.find_by_order(idx)];
		}
	}
	FOR(i, 0, Q)
	{
		cout << ans[i] << '\n';
	}
	return 0;
	//sort elements first by value, then by location.
}