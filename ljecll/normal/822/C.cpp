/*
PROG: cf822c
LANG: C++
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 200010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, X;
ll ans = LLINF;
pair<pll, ll> arr[MAXN];
vector<pair<pii, pll> > v;
ll dp[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf822c.in", "r"))
	{	
		freopen ("cf822c.in", "r", stdin);
		freopen ("cf822c.out", "w", stdout);
	}
	cin >> N >> X;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		v.PB(MP(MP(arr[i].first.first, 0), MP(arr[i].first.second - arr[i].first.first + 1, arr[i].second)));
		v.PB(MP(MP(arr[i].first.second, 1), MP(arr[i].first.second - arr[i].first.first + 1, arr[i].second)));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < MAXN; i++)
	{
		dp[i] = LLINF;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (!v[i].first.second && X >= v[i].second.first)
		{
			ans = min(ans, v[i].second.second + dp[X - v[i].second.first]);
		}
		else
		{
			dp[v[i].second.first] = min(dp[v[i].second.first], v[i].second.second);
		}
	}
	if (ans >= LLINF)
	{
		cout << "-1\n";
		return 0;
	}
	cout << ans << '\n';
	return 0;
	//time
	//start or end? (1 vs 0)
	//duration
	//cost
}