#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int tord[400];
const int maxn = 110;

int dp[maxn][maxn];
int wy[maxn][maxn];

int forw[maxn][maxn], bacw[maxn][maxn];
int best[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	if (n == 1){
		cout << t << endl;
		exit(0);
	}

	vector<int> lst(n);

	set<int> tc;

	for (int i = 0; i < n; ++i){
		cin >> lst[i];
		tc.insert(lst[i]);
	}

	int tot = 1;
	for (auto val : tc){
		tord[val] = tot++;
	}

	for (int i = 0; i < n; ++i){
		lst[i] = tord[lst[i]];
	}


	for (int i = 0; i < n; ++i){
		dp[i][i] = 1;
		wy[lst[i]][lst[i]] = max(wy[lst[i]][lst[i]], 1);
		for (int j = i + 1; j < n; ++j){
			if (lst[j] < lst[i]) dp[i][j] = 0;
			else{
				dp[i][j] = 2;
				for (int k = i + 1; k < j; ++k)
				{
					if (lst[i] <= lst[k] && lst[k] <= lst[j])
						dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
			wy[lst[i]][lst[j]] = max(wy[lst[i]][lst[j]], dp[i][j]);			
		}
	}

	int ans = 0;

	for (int i = 1; i < tot; ++i)
		for (int k = 1; k < i; ++k){
			bacw[i][k] = bacw[i - 1][k];
			for (int j = 1; j < i; ++j)
				bacw[i][k] = max(bacw[i][k], bacw[j][k - 1] + wy[j][i]);
		}

	for (int i = tot - 1; i; --i)
		for (int k = 1; k < tot - i; ++k){
			forw[i][k] = forw[i + 1][k];
			for (int j = tot - 1; j > i; --j)
				forw[i][k] = max(forw[i][k], forw[j][k - 1] + wy[i][j]);
		}

	for (int i = 1; i < n; ++i){
		for (int k = 0; k < n && k <= t; ++k){
			for (int s1 = 0; s1 <= k; ++s1){
				best[i][k] = max(best[i][k], forw[i][s1] + bacw[i][k - s1]);
				ans = max(ans, best[i][k] + (t - k) * wy[i][i]);
			}
		}
	}	

	cout << ans << endl;

	return 0;
}