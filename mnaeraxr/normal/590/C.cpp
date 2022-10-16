#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 1010;
const int oo = 0x3f3f3f3f;

int n, m;
char board[maxn][maxn];
int dist[3][maxn][maxn];
int dp[8][maxn][maxn];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool inside(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

int solve(int mask, int x, int y){
	int &val = dp[mask][x][y];
	if (val != -1) return val;
	val = oo;

	int tbits = __builtin_popcount(mask);
	if (tbits == 1){
		val = dist[__lg(mask)][x][y]; 
	}
	else if (tbits == 2){
		int i = __lg(mask);
		int j = __lg(mask ^ (1 << i));
		val = min(val, dist[i][x][y] + dist[j][x][y] - (board[x][y] == '.'));
		for (int k = 0; k < 4; ++k){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (inside(nx, ny) && dist[i][nx][ny] < dist[i][x][y] && dist[j][nx][ny] < dist[j][x][y])
				val = min(val, solve(mask, nx, ny) + (board[x][y] == '.'));
		}
	}
	else{
		val = min(val, solve(1 + 2, x, y) + dist[2][x][y] - (board[x][y] == '.'));
		val = min(val, solve(1 + 4, x, y) + dist[1][x][y] - (board[x][y] == '.'));
		val = min(val, solve(4 + 2, x, y) + dist[0][x][y] - (board[x][y] == '.'));
	}

	// cout << bitset<3>(mask) << " " << val << " " << x << " " << y << endl;
	return val;
}

void bfs(char cur){
	int idx = cur - '1';
	queue<pii> q;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (board[i][j] == cur){
				dist[idx][i][j] = 0;
				q.push(pii(i, j));
			}
		}
	}
	while (!q.empty()){
		auto cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		for (int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inside(nx, ny) && board[nx][ny] != '#' && dist[idx][nx][ny] == oo){
				dist[idx][nx][ny] = dist[idx][x][y] + 1;
				q.push(pii(nx, ny));
			}
		}
	}
}

int d[3][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> board[i];

	memset(dist, oo, sizeof dist);
	bfs('1'); bfs('2'); bfs('3');

	memset(d, oo, sizeof d);
	memset(dp, -1, sizeof dp);

	int ans = oo;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){

			for (int k = 0; k < 3; ++k){
				if (board[i][j] == (char)('1' + k)){
					for (int t = 0; t < 3; ++t)
						d[k][t] = min(d[k][t], dist[t][i][j]);
				}
			}

			bool ok = true;
			for (int k = 0; k < 3 && ok; ++k){
				if (dist[k][i][j] == oo) ok = false;
			}
			if (!ok) continue;

			int cur = solve(7, i, j);
			if (cur < ans){
				// cout << i << " " << j << endl;
				ans = cur;
			}
		}
	}
	// for (int i = 0; i < 3; ++i)
	// 	for (int j = 0; j < 3; ++j)
	// 		cout << d[i][j] << " \n"[j + 1 == 3];
	ans = min(ans, d[0][1] + d[1][2] - 2);
	ans = min(ans, d[0][2] + d[2][1] - 2);
	ans = min(ans, d[1][0] + d[0][2] - 2);

	if (ans >= oo - 1) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}