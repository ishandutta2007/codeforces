#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

int n, m;
int minD = 1e9;
vector<string> G, A, T;
vector<char> DNA = { 'A', 'C', 'G', 'T' }, bDNA = DNA;

const int MAX = 150 * 1000 + 1;
int mincH[MAX][4][4], mincV[MAX][4][4];

ii opp(int a, int b) {
	int c = 0;
	while (c == a || c == b) c++;
	int d = c + 1;
	while (d == a || d == b) d++;
	return ii(c, d);
}

void reconstrH(int x, int y) {
	int i = n-1;
	while (i >= 0) {
		int u, v, inc1 = 0, inc2 = 0;
		tie(u, v) = opp(x, y);
		REP(j, m) {
			inc1 += G[i][j] != DNA[(j&1) ? x : y];
			inc2 += G[i][j] != DNA[(j&1) ? y : x];
		}

		int px = x, py = y;
		if (inc1 > inc2) swap(px, py);
		REP(j, m) G[i][j] = DNA[(j&1) ? px : py];

		x = u;
		y = v;
		i--;
	}

	REP(j, n) printf("%s\n", G[j].c_str());
}

void reconstrV(int x, int y) {
	int i = m-1;
	while (i >= 0) {
		int u, v, inc1 = 0, inc2 = 0;
		tie(u, v) = opp(x, y);
		REP(j, n) {
			inc1 += G[j][i] != DNA[(j&1) ? x : y];
			inc2 += G[j][i] != DNA[(j&1) ? y : x];
		}

		int px = x, py = y;
		if (inc1 > inc2) swap(px, py);
		REP(j, n) G[j][i] = DNA[(j&1) ? px : py];

		x = u;
		y = v;
		i--;
	}

	REP(j, n) printf("%s\n", G[j].c_str());
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	G.resize(n);
	A.resize(n);
	T.resize(n);

	getline(cin, G[0]);
	REP(i, n) getline(cin, G[i]);
	REP(i, n) T[i] = G[i];

	/* REP(y, 4) REP(x, y) {
		// (x, y)
		int u, v;
		tie(u, v) = opp(x, y);
		fprintf(stderr, "(%d,%d) -> (%d,%d)\n", x, y, u, v);
	} */

	// horizontal
	memset(mincH[0], 0, sizeof(mincH[0]));
	for (int i = 0; i < n; i++) {
		REP(y, 4) REP(x, y) {
			// (x, y)
			int u, v, inc1 = 0, inc2 = 0;
			tie(u, v) = opp(x, y);
			REP(j, m) {
				inc1 += G[i][j] != DNA[(j&1) ? x : y];
				inc2 += G[i][j] != DNA[(j&1) ? y : x];
			}
			mincH[x][y][i+1] = mincH[u][v][i] + min(inc1, inc2);
		}
	}

	memset(mincV[0], 0, sizeof(mincV[0]));
	for (int i = 0; i < m; i++) {
		REP(y, 4) REP(x, y) {
			// (x, y)
			int u, v, inc1 = 0, inc2 = 0;
			tie(u, v) = opp(x, y);
			REP(j, n) {
				inc1 += G[j][i] != DNA[(j&1) ? x : y];
				inc2 += G[j][i] != DNA[(j&1) ? y : x];
			}
			mincV[x][y][i+1] = mincV[u][v][i] + min(inc1, inc2);
		}
	}

	int mincost = 1e9;
	REP(y, 4) REP(x, y) mincost = min(mincost, mincH[x][y][n]);
	REP(y, 4) REP(x, y) mincost = min(mincost, mincV[x][y][m]);
		
	fprintf(stderr, "mincost: %d\n", mincost);

	REP(y, 4) REP(x, y) if (mincost == mincH[x][y][n]) return reconstrH(x,y), 0;
	REP(y, 4) REP(x, y) if (mincost == mincV[x][y][m]) return reconstrV(x,y), 0;
	assert(false);
	return 0;
}