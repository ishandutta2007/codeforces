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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vvi A(n, vi(n));
	REP(i, n) REP(j, n) cin >> A[i][j];

	REP(i, n) {
		A[i][i] = true;

		queue<int> q;
		REP(j, n) if (A[i][j]) q.push(j);
		while (!q.empty()) {
			int j = q.front();
			q.pop();
			REP(k, n) if (A[j][k] && !A[i][k])
				A[i][k] = true, q.push(k);
		}
	}

	vvi comps;
	vector<bool> seen(n, false);
	vi cidx(n, -1);
	REP(i, n) {
		if (cidx[i] >= 0) continue;
		comps.eb();
		REP(j, n) if (A[i][j] && A[j][i]) {
			comps.back().pb(j);
			cidx[j] = (int) comps.size() - 1;
		}
	}

	int nco = (int) comps.size();

	/*
	for (auto v : comps) {
		cerr << "now: ";
		for (int i : v) cerr << i << " ";
		cerr<< endl;
	}
	*/

	vector<vi> deps(nco);
	vi indeg(nco, 0);
	vector<vector<bool>> isdep(nco, vector<bool>(nco, false));
	REP(i, n) REP(j, n) if (A[i][j] && !A[j][i]) {
		// i -> j
		int ci = cidx[i], cj = cidx[j];
		if (isdep[ci][cj]) continue;
		isdep[ci][cj] = true;
		deps[ci].pb(cj);
		indeg[cj]++;
	}

	vi lvl(nco), tocomp(nco);
	queue<int> topq;
	REP(i, nco) if (indeg[i] == 0) topq.push(i);
	int cntr = 0;
	while (!topq.empty()) {
		int cur = topq.front();
		tocomp[cntr] = cur;
		lvl[cur] = cntr++;
		topq.pop();
		for (int nxt : deps[cur]) {
			if (--indeg[nxt] == 0) topq.push(nxt);
		}
	}

	int H = 2 * nco - 1;
	int W = 4, L = max(n, 3 * nco * (nco - 1) / 2);

	// -1 <-> obstructed
	vector<vvi> G(H, vvi(W, vi(L, -1)));

	// whole top row is accessible
	REP(i, nco) REP(j, L) G[i+i][3][j] = 0;

	REP(i, n) {
		int ath = lvl[cidx[i]];
		G[ath + ath][3][i] = i + 1;
	}

	// show deps

	int offset = 0;
	REP(i, nco) for (int j : deps[i]) {
		int frh = lvl[i];
		int toh = lvl[j];
		assert(toh > frh);

		frh *= 2;
		toh *= 2;

		G[frh][2][offset + 1] = 0;
		for (int h = frh; h <= toh; h++) G[h][1][offset + 1] = 0;
		G[toh][2][offset + 1] = 0;

		offset += 3;
	}

	printf("%d %d %d\n", L, W, H);
	REP(h, H) {
		REP(y, W) {
			REP(x, L) {
				if (G[h][y][x] <= 0) {
					printf("%c", G[h][y][x] == 0 ? '.' : '#');
				} else printf("%d", G[h][y][x]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}