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

const int MAXS = 1e4;
int sizeL = MAXS, sizeR = MAXS;

bool vis[MAXS];
int par[MAXS]; // par : R -> L
vi adj[MAXS]; // adj : L -> (N -> R)

bool match(int u) {
	for (int v : adj[u]) {
		if (vis[v]) continue;
		vis[v] = true;
		if (par[v] == -1 || match(par[v])) {
			par[v] = u;
			return true;
		}
	}
	return false;
}
// perfect matching iff ret == sizeL == sizeR
int maxmatch() {
	fill_n(par, sizeR, -1);
	int ret = 0;
	for (int i = 0; i < sizeL; i++) {
		fill_n(vis, sizeR, false);
		ret += match(i);
	}
	return ret;
}

ll try_board(int n, int m)
{
	vvi idxl(n, vi(m, 0)), idxr(n, vi(m, 0));
	int nl = 0, nr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				idxl[i][j] = nl++;
			} else {
				idxr[i][j] = nr++;
			}
		}
	}

	sizeL = nl;
	sizeR = nr;

	REP(i, nl) adj[i].clear();

	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++) {
			if (abs(i - x) >= 3) continue;
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 != 0) continue;
				for (int y = 0; y < m; y++) {
					int d = abs(i - x) + abs(j - y);
					if (d != 3) continue;

					assert((x + y) % 2 == 1);
					adj[idxl[i][j]].pb(idxr[x][y]);
				}
			}
		}
	}

	return 2LL * maxmatch();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

    if (N > M) swap(N, M);
    // N <= M

	int rN = N % 6, rM = M % 6;

	ll ret = 1LL * N * M - 1LL * (rN * rM);
	for (int qN = 0; qN < 3 && 6 * qN + rN <= N; qN++) {
		for (int qM = 0; qM < 3 && 6 * qM + rM <= M; qM++) {
			int sn = 6 * qN + rN;
			int sm = 6 * qM + rM;

			ll alt = 1LL * N * M;
			alt -= 1LL * sn * sm;
			alt += try_board(sn, sm);

			ret = max(ret, alt);
		}
	}
	
	if (N == 2) {
        int tmp[4] = { 0, -2, -4, -2 };
	    ret = max(ret, 2LL * M + tmp[M % 4]);
	}

	cout << ret << endl;

	return 0;
}