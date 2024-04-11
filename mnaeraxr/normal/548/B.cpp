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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<int> M(n);
	vector<vector<bool>> board(n, vector<bool>(m));

	for (int i = 0; i < n; ++i){
		int cnt = 0;
		for (int j = 0; j < m; ++j){
			int cur; cin >> cur;
			board[i][j] = cur;
			if (board[i][j]) ++cnt;
			else cnt = 0;
			M[i] = max(M[i], cnt);
		}
	}

	while (q--){
		int x, y; cin >> x >> y;
		x--; y--;
		board[x][y] = !board[x][y];
		int cnt = 0;
		M[x] = 0;
		for (int i = 0; i < m; ++i){
			if (board[x][i]) ++cnt;
			else cnt = 0;
			M[x] = max(M[x], cnt);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, M[i]);

		cout << ans << endl;
	}

	return 0;
}