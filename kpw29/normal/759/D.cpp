#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<51> bset;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 5010
int T, n, m, a, b, c, type, place;

int dp[maxn][maxn];
int co[maxn];
ll bucket[30];
int pi[maxn], szu[maxn];
ll pref[maxn];
inline int getSum(int a, int b) {
	//cout << a << ' ' << b << endl;
	return (pref[b] - pref[a-1] + mod)%mod;
}

int main()
{
	co[0] = 0;
	boost;
	cin >> n;
	string s;
	cin >> s;
	FOR(i, 0, n-1) co[i + 1] = s[i] - 'a' + 1;
	FOR(i, 0, 30) szu[i] = -1;
	FOR(i, 1, n)
	{
		pi[i] = szu[co[i]];
		szu[co[i]] = i;
	}

	dp[0][0] = 1;
	FOR(i, 1, n)
	{
		pref[0] = dp[i-1][0];
		FOR(j, 1, n)
		{
			pref[j] = pref[j-1] + dp[i-1][j];
			while (pref[j] >= mod) pref[j] -= mod;
		}

		FOR(j, 1, n)
		{
			dp[i][j] = getSum(pi[j] + 1, j);
			//ponadto, mozemy wziac jeszcze dp ze wszystkich poprzednich pozycji, pod warunkiem, ze nie bylo po drodze innej literki
			while (dp[i][j] >= mod) dp[i][j] -= mod;
		}
	}
	
	/*FOR(i, 1, n)
	{
		FOR(j, 1, n) cout << dp[i][j] << ' ';
		cout << endl;
	}*/
	ll wyn = 0;
	FOR(j, 1, n) wyn += dp[n][j];
	wyn %= mod;
	cout << wyn;
}