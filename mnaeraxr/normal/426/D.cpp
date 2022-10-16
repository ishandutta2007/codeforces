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

int T1[110][110], T2[110][110];
int Y[110];

int solve(int n, int m, int M[110][110])
{
	int ans = oo;
	for (int i = 0; i < n; ++i){
		int val = 0;
		for (int j = 0; j < m; ++j)
			Y[j] = M[i][j];

		for (int k = 0; k < n; ++k){
			if (k == i) continue;

			int v0 = 0, v1 = 0;
			for (int j = 0; j < m; ++j){
				if (M[k][j] != Y[j]) v0++;
				else v1++;
			}
			val += min(v0, v1);
		}
		ans = min(ans, val);
	}
	return ans;
}

int solve1(int n, int m, int M[110][110])
{
	int ans = oo;
	for (int i = 0; i < (1 << m); ++i){
		for (int j = 0; j < m; ++j)
			Y[j] = (i & (1 << j)) ? 1 : 0;

		int val = 0;
		for (int k = 0; k < n; ++k){
			int v0 = 0, v1 = 0;
			for (int j = 0; j < m; ++j){
				if (M[k][j] != Y[j]) v0++;
				else v1++;
			}
			val += min(v0, v1);
		}
		ans = min(ans, val);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			cin >> T1[i][j];
			T2[j][i] = T1[i][j];
		}

	int ans = oo;
	if (m <= k){
		ans = min(ans, solve1(n, m, T1));
	}
	else{
		ans = min(solve(n, m, T1), solve(m, n, T2));
	}
	if (ans > k) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}