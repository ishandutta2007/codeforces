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

const int INF = 2e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int x, y;
	int r, c;
	cin >> n >> m >> r >> c >> x >> y;
	r--; c--;

	vector<vector<bool>> G(n, vector<bool>(m));
	REP(i, n) REP(j, m) { char ch; cin >> ch; G[i][j] = ch != '*'; }

	// priority_queue< pair<int, ii>, vector< pair<int, ii> >, greater<pair<int, ii>> > q, nq;
	queue<ii> q;
	vector<ii> nxtbatch;

	vvi minl(n, vi(m, INF));
	minl[r][c] = 0;
	nxtbatch.eb(r, c);

	while (!nxtbatch.empty()) {
		while (!nxtbatch.empty()) q.push(nxtbatch.back()), nxtbatch.pop_back();

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			int cx = cur.x, cy = cur.y;
			int alt = minl[cx][cy];

			if (cy > 0 && G[cx][cy - 1] && minl[cx][cy - 1] > alt + 1) {
				minl[cx][cy - 1] = alt + 1;
				nxtbatch.eb(cx, cy - 1);
			}
			if (cy + 1 < m && G[cx][cy + 1] && minl[cx][cy + 1] > alt) {
				minl[cx][cy + 1] = alt;
				q.emplace(cx, cy + 1);
			}
			if (cx > 0 && G[cx - 1][cy] && minl[cx - 1][cy] > alt) {
				minl[cx - 1][cy] = alt;
				q.emplace(cx - 1, cy);
			}
			if (cx + 1 < n && G[cx + 1][cy] && minl[cx + 1][cy] > alt) {
				minl[cx + 1][cy] = alt;
				q.emplace(cx + 1, cy);
			}
		}
	}

	int ans = 0;
	REP(i, n) REP(j, m) {
		int nrls = minl[i][j];
		int nrrs = nrls + (j - c);
		if (nrls <= x && nrrs <= y) {
			// cerr << i << " " << j << ": " << nrls << " " << nrrs << endl;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}