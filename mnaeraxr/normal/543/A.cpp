#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = 510;

int dp[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, b, mod;
	cin >> n >> m >> b >> mod;

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		for (int l = 1; l <= m; ++l){
			for (int j = a; j <= b; ++j){
				dp[l][j] += dp[l - 1][j - a];
				dp[l][j] %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= b; ++i)
	{
		ans += dp[m][i];
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}