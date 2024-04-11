#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

char B[200][200];
int dp[200][200];
int val[200][200];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		cin >> B[i];
	}

	int ans = 0;

	for (int i = n - 1; i >= 0; --i){
		int dx = 0;
		for (int j = m - 1; j >= 0; --j){
			val[i][j] = B[i][j] == 'B' ? 1 : -1;
			dp[i][j] += dx;

			if (dp[i][j] != val[i][j]){
				++ans;
				int r = val[i][j] - dp[i][j];
				dx += r;
				dp[i][j] += r;
			}

			if (i) dp[i - 1][j] = dp[i][j];
		}
	}

	cout << ans << endl;

	return 0;
}