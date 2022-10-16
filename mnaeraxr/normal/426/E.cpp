#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
const int MAXEDIVS = (int)3e2 + 10;

int A[MAXN], B[MAXN];
vi lst[MAXN];
int dp[MAXN][MAXEDIVS];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s, e;
	cin >> n >> m >> s >> e;

	for (int i = 1; i <= n; ++i){
		cin >> A[i];
	}

	for (int i = 1; i <= m; ++i){
		cin >> B[i];
		lst[ B[i] ].push_back(i);
	}

	memset(dp, oo, sizeof dp);
	for (int i = 0; i < MAXN; ++i)
		dp[i][0] = 0;

	int ans = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; e * j <= s; ++j){
			dp[i][j] = dp[i - 1][j];
			int val = upper_bound(lst[A[i]].begin(), lst[A[i]].end(), dp[i - 1][j - 1]) - lst[A[i]].begin();

			if (val < (int)lst[A[i]].size())
				dp[i][j] = min(dp[i][j], lst[A[i]][val]);

//			cout << i << " " << j << " " << dp[i][j] << endl;

			if (j * e + i + dp[i][j] <= s)
				ans = max(ans, j);
		}
	}

	cout << ans << endl;

	return 0;
}