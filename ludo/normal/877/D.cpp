#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define rs resize
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int maxn = 1001;

int N, M, K;
ii fr, to;
bool g[maxn][maxn] = {};
int dist[maxn][maxn];

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

void run() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			g[i][j] = (S[j] == '.');
		}
	}
	cin >> fr.x >> fr.y >> to.x >> to.y;
	fr.x--; fr.y--; to.x--; to.y--;

	for (int i = 0; i < maxn; i++)
		fill_n(dist[i], maxn, INF);

	queue<ii> q;
	dist[fr.x][fr.y] = 0;
	q.push(fr);
	while (!q.empty()) {
		ii cur = q.front();
		int cx = cur.x, cy = cur.y;
		q.pop();
		// cerr << "CUR: " << cur.x << ", " << cur.y << ": " << dist[cur.x][cur.y] << endl;
		for (int dir = 0; dir < 4; dir++) {
			int x = cx + dx[dir], y = cy + dy[dir];
			int steps = 1;
			while (steps <= K && 0 <= x && x < N && 0 <= y && y < M && g[x][y] && dist[cx][cy] < dist[x][y]) {
				if (dist[x][y] == INF) {
					dist[x][y] = dist[cx][cy] + 1;
					q.emplace(x, y);
				}
				x += dx[dir];
				y += dy[dir];
				steps++;
			}
		}
	}
	if (dist[to.x][to.y] == INF) dist[to.x][to.y] = -1;
	cout << dist[to.x][to.y] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}