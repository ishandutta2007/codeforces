/*input
6 3
aacabc
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _co(x);}
#define bit(x,y) ((x>>y)&1)
void _co() {cout << endl;}
template<typename T, typename... Ts> void _co(const T& value, const Ts&... values) {cout << ' ' << value; _co(values...);}
template<typename T, typename... Ts> void co(const T& value, const Ts&... values) {cout << "deb: " << value; _co(values...);}
// change cout to cerr for debug in crash
#ifdef UncleGrandpa
const int N = (1 << 10);
#else
const int N = (1 << 20);
#endif
int n, m;
string s;
int cnt[20][20];
int scntx[20], scnty[20];
int cntx[20][N];
int cnty[20][N];
long long dp[N];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	cin >> s; s.resize(distance(s.begin(), unique(s.begin(), s.end())));
	loop(i, 1, s.size() - 1) {
		cnt[s[i - 1] - 'a'][s[i] - 'a']++;
	}
	loop(i, 0, m - 1) {
		loop(j, 0, m - 1) scntx[i] += cnt[j][i];
		loop(j, 0, m - 1) scnty[i] += cnt[i][j];
		loop(mask, 1, (1 << m) - 1) {
			int p = __builtin_ctzll(mask);
			cntx[i][mask] = cntx[i][mask ^ (1 << p)] + cnt[p][i];
			cnty[i][mask] = cnty[i][mask ^ (1 << p)] + cnt[i][p];
		}
	}

	fill(dp, dp + (1 << m), 1e18);
	dp[0] = 0;
	loop(mask, 1, (1 << m) - 1) {
		int numbit = __builtin_popcount(mask);
		loop(i, 0, m - 1) {
			if (!bit(mask, i)) continue;
			auto prex = cntx[i][mask]; // j i
			auto prey = cnty[i][mask]; // i j
			long long nval = dp[mask ^ (1 << i)] + 1LL * numbit * (2 * prex + 2 * prey - scntx[i] - scnty[i]);
			// co(i, bitset<3>(mask), prex, aftx, prey, afty, (prex + prey - aftx - afty));
			// co(dp[mask ^ (1 << i)], 1LL * numbit * (prex + prey - aftx - afty));
			dp[mask] = min(dp[mask], nval);
		}
	}
// cout << dp[0b110] << endl;
	cout << dp[(1 << m) - 1] << endl;
}