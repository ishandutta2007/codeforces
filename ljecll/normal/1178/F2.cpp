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
#define LLINF 2696969696969696969ll
#define MAXN 1000013
#define MAXM 513

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
int arr[MAXN];
vi pos[MAXM];
pii sparse[20][MAXN];
bitset<MAXM> vis[MAXM];
ll dp[MAXM][MAXM];
int lt[MAXM], rt[MAXM];
int parent[MAXM];
vi edge[MAXM];
ll ans = 1;
vi nums;

pii query(int l, int r)
{
	int sz = 31 - __builtin_clz(r - l + 1);
	return min(sparse[sz][l], sparse[sz][r - (1 << sz) + 1]);
}
bool cmp(int a, int b)
{
	return lt[a] < lt[b];
}
ll solve(int l, int r)
{
	//find the smallest guy in (l...r)
	// cerr << "HI " << l << ' ' << r << endl;
	if (l > r) return 1;
	if (vis[l][r])
	{
		return dp[l][r];
	}
	vis[l][r] = true;
	int ind = l;
	FOR(i, l, r + 1)
	{
		if (nums[i] < nums[ind])
		{
			ind = i;
		}
	}
	ll lsum = 0, rsum = 0;
	FOR(i, l, ind + 1)
	{
		lsum += solve(l, i - 1) * solve(i, ind - 1);
		lsum %= INF;
	}
	FOR(j, ind, r + 1)
	{
		rsum += solve(ind + 1, j) * solve(j + 1, r);
		rsum %= INF;
	}
	dp[l][r] = lsum * rsum % INF;
	// cerr << l << ' ' << r << ' ' << dp[l][r] << endl;
	return dp[l][r];
}
ll work(vi nums)
{
	FOR(i, 0, SZ(nums))
	{
		FOR(j, 0, SZ(nums))
		{
			vis[i][j] = false;
		}
	}
	return solve(0, SZ(nums) - 1);
}
void dfs(int u)
{
	//oh wait can't you just run this dp or something
	sort(ALL(edge[u]), cmp);
	for (int v : edge[u])
	{
		dfs(v);
	}
	int rg = lt[u];
	for (int v : edge[u])
	{
		if (lt[v] != rg + 1)
		{
			ans *= work(nums); ans %= INF;
			nums.clear();
		}
		nums.PB(v);
		rg = rt[v];
	}
	ans *= work(nums); ans %= INF; nums.clear();
	// for (int x : nums)
	// {
	// 	cerr << x << ' ';
	// }
	// cerr << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	M++;
	FOR(i, 0, N)
	{
		cin >> arr[i];
		pos[arr[i]].PB(i);
	}
	FOR(i, 0, N)
	{
		sparse[0][i] = {arr[i], i};
	}
	FOR(i, 0, 19)
	{
		FOR(j, 0, N)
		{
			if (j + (2 << i) > N) break;
			sparse[i + 1][j] = min(sparse[i][j], sparse[i][j + (1 << i)]);
			// cerr << i << ' ' << j + (1 << i) << ' ' << sparse[i][j + (1 << i)].fi << endl;
		}
	}
	FOR(i, 1, M)
	{
		FOR(j, 1, SZ(pos[i]))
		{
			int l = pos[i][j - 1], r = pos[i][j];
			// cerr << l << ' ' << r << ' ' << query(l, r).fi << endl;
			if (query(l, r).fi != i)
			{
				cout << "0\n";
				return 0;
			}
		}
		lt[i] = pos[i][0];
		rt[i] = pos[i].back();
	}
	FOR(i, 1, M)
	{
		parent[i] = 0;
		FOR(j, 1, i)
		{
			if (lt[j] < lt[i] && rt[i] < rt[j])
			{
				parent[i] = j;
			}
		}
		edge[parent[i]].PB(i);
		// cerr << parent[i] << " -> " << i << endl;
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}