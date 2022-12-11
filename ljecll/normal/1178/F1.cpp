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
ll dp[MAXM][MAXM];
bitset<MAXM> vis[MAXM];
int ans;

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
		if (arr[i] < arr[ind])
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
	//oh ok so it's sorta like you're putting down barriers
	//each time the barriers have to be:
	//1) one to the left, another to the right
	//2) they have to be in the range you're currently in
	//successive ranges have to be contained inside each other
	ans = solve(0, N - 1);
	cout << ans << '\n';
	return 0;
}