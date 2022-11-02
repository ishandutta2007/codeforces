#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxn = 10;
const int maxv = 3 * maxn * maxn;

int N, A[maxn * maxn]; // ordering

ii D[maxv][maxv];

const ii INF(-1, -1);

ii operator+(ii a, ii b) { return ii(a.x+b.x, a.y+b.y);}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	REP(i, N) REP(j, N) {
		int x;
		cin >> x;
		A[x - 1] = N * i + j;
	}

	int V = 3 * N * N;

	REP(i, V) REP(j, V) D[i][j] = INF;
	REP(i, N * N) {
		D[i + 0 * N * N][i + 1 * N * N] = ii(1, 1);
		D[i + 0 * N * N][i + 2 * N * N] = ii(1, 1);
		D[i + 1 * N * N][i + 0 * N * N] = ii(1, 1);
		D[i + 1 * N * N][i + 2 * N * N] = ii(1, 1);
		D[i + 2 * N * N][i + 0 * N * N] = ii(1, 1);
		D[i + 2 * N * N][i + 1 * N * N] = ii(1, 1);
	}

	REP(i, N * N) {
		REP(j, N * N) {
			if (i == j) continue;
			int dx = abs((i / N) - (j / N));
			int dy = abs((i % N) - (j % N));
			if (dx == 0 || dy == 0) {
				D[i][j] = ii(1, 0);
			}
			if (dx == dy) {
				D[i + N*N][j + N*N] = ii(1, 0);
			}
			if (min(dx, dy) == 1 && max(dx, dy) == 2) {
				D[i + 2*N*N][j + 2*N*N] = ii(1, 0);
			}
		}
	}

	REP(j, V) REP(i, V) REP(k, V) {
		if (D[i][j] == INF || D[j][k] == INF) continue;
		ii alt = D[i][j] + D[j][k];
		if (D[i][k] == INF || alt < D[i][k]) D[i][k] = alt;
	}

	// find shortest path
	vector<ii> SP(3, ii(0, 0)), NSP(3);
	for (int i = 1; i < N * N; i++) {
		REP(u, 3) NSP[u] = INF;

		REP(u, 3) REP(v, 3) {
			int fr = A[i - 1], to = A[i];

			int fv = fr + v * N * N;
			int tv = to + u * N * N;

			if (D[fv][tv] == INF || SP[v] == INF) continue;
			ii alt = SP[v] + D[fv][tv];
			if (NSP[u] == INF || alt < NSP[u])
				NSP[u] = alt;
		}

		REP(u, 3) SP[u] = NSP[u];
	}

	ii ans = INF;
	REP(u, 3) {
		if (ans == INF || (NSP[u] != INF && NSP[u] < ans))
			ans = NSP[u];
	}
	cout << ans.x << " " << ans.y << endl;
	return 0;
}