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
#define MAXN 300013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, Q, K;
int arr[MAXN];
pii pos[MAXN];
int dp[MAXN];
vi compress;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Q;
	while(Q--)
	{
		ans = 0;
		compress.clear();
		cin >> N;
		FOR(i, 0, N)
		{
			cin >> arr[i];
			compress.PB(arr[i]);
		}
		sort(ALL(compress));
		compress.erase(unique(ALL(compress)), compress.end());
		FOR(i, 0, N)
		{
			arr[i] = LB(ALL(compress), arr[i]) - compress.begin();
		}
		K = SZ(compress);
		FOR(i, 0, K)
		{
			pos[i] = {N, -1};
		}
		FOR(i, 0, N)
		{
			ckmin(pos[arr[i]].fi, i);
			ckmax(pos[arr[i]].se, i);
		}
		dp[K - 1] = K - 1;
		FORD(i, K - 1, 0)
		{
			if (pos[i].se < pos[i + 1].fi)
			{
				dp[i] = dp[i + 1];
			}
			else
			{
				dp[i] = i;
			}
		}
		FOR(i, 0, K)
		{
			ckmax(ans, dp[i] - i + 1);
		}
		cout << K - ans << '\n';
	}
	return 0;
}