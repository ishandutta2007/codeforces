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
const int64 MOD = (int64)1e9 + 7;
const int MAXN = (int)1e5 + 10;

vi ady[MAXN];
int color[MAXN];
bool mk[MAXN];
int64 dp[MAXN][2];
int father[MAXN];

int64 modexp(int64 v, int64 p){
	if (!p) return 1LL;
	int64 ans = modexp(v * v % MOD, p / 2);
	if (p & 1) ans = ans * v % MOD;
	return ans;
}

int64 inverse(int64 v){
	return modexp(v, MOD - 2);
}

void dfs(int s)
{
	dp[s][color[s]] = 1;
	for (int i = 0; i < (int)ady[s].size(); ++i){
		int nx = ady[s][i];
		dfs(nx);
		if (color[s]){
			dp[s][1] = dp[s][1] * (dp[nx][0] + dp[nx][1]) % MOD;
		}
		else{
			dp[s][1] = (dp[s][0] * dp[nx][1] % MOD + dp[s][1] * dp[nx][0] % MOD + dp[s][1] * dp[nx][1]) % MOD;
			dp[s][0] = dp[s][0] * (dp[nx][1] + dp[nx][0]) % MOD;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; ++i){
		int v; cin >> v;
		ady[v].push_back(i);
	}
	for (int i = 0; i < n; ++i)
	{
		father[i] = -1;
		cin >> color[i];
	}

	dfs(0);

	cout << dp[0][1] << endl;

	return 0;
}