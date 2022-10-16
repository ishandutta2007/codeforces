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
const int MAXN = (int)2e5 + 10;
const int oo = 1 << 29;

vi ady[MAXN];

bool mk[MAXN];
int dp[MAXN][2], tot;

void dfs(int s){
	mk[s] = true;

	int mn = oo;
	int sum = 0;

	for (int i = 0; i < SZ(ady[s]); ++i){
		int nx = ady[s][i];
		if (mk[nx]) continue;
		dfs(nx);
		sum += dp[nx][0] + 1;
		mn = min(mn, dp[nx][1]);
	}
	if (mn == oo) dp[s][0] = dp[s][1] = 0, ++tot;
	else{
		dp[s][0] = mn;
		dp[s][1] = sum - 1;
	}
}

int other_dp[MAXN][2];

void other_dfs(int s){
	mk[s] = true;

	int mn = oo;
	int sum = 0;

	for (int i = 0; i < SZ(ady[s]); ++i){
		int nx = ady[s][i];
		if (mk[nx]) continue;
		other_dfs(nx);
		sum += other_dp[nx][1] + 1;
		mn = min(mn, other_dp[nx][0]);
	}

	if (mn == oo) other_dp[s][0] = other_dp[s][1] = 0;
	else{
		other_dp[s][0] = sum - 1;
		other_dp[s][1] = mn;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	dfs(1);
	memset(mk, false, sizeof mk);
	other_dfs(1);
	
	cout << tot - dp[1][0] << " " << 1 + other_dp[1][0] << endl;

	return 0;
}