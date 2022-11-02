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

const int maxn = 50, maxk = 2001;
const int maxcandy = 2501;
// const int maxcandy = 20;

int N, S, K, R[maxn];
int C[maxn];

int DP[maxn][maxcandy] = {};

const int INF = 1e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S >> K;
	S--;
	REP(i, N) cin >> R[i];
	string line; cin >> line;
	REP(i, N) {
		C[i] = (line[i] == 'R') + (line[i] != 'B');
	}
	// R -> 2, G -> 1, B -> 0

	REP(i, N) REP(j, maxcandy) DP[i][j] = INF;

	vii order;
	REP(i, N) order.eb(R[i], i);
	sort(all(order));

	int ret = INF;

	REP(i, N) {
		int r = order[i].x, cur = order[i].y;
		DP[cur][r] = min(DP[cur][r], abs(cur - S));
		REP(j, i) {
			int prv = order[j].y;
			// previous
			if (R[prv] >= R[cur]) continue;
			if (C[prv] == C[cur]) continue;
			for (int c = 0; r + c < maxcandy; c++) {
				DP[cur][r + c] = min(DP[cur][r + c], DP[prv][c] + abs(prv - cur));
			}
		}
/*
		cerr << "CURRENT: " << cur << endl;
		REP(c, maxcandy) if (DP[cur][c] != INF) cerr << c << " => " << DP[cur][c] << ", ";
		cerr << endl;*/
		for (int c = K; c < maxcandy; c++) {
			if (ret > DP[cur][c]) {
				ret = DP[cur][c];
			}
		}
	}

	if (ret == INF) ret = -1;
	cout << ret << endl;
	
	return 0;
}