#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int maxn = 100'005, maxq = 1000, maxN = 251;

int n, q, N[3] = {};
string S, T[3];
int nxt[maxn][26];
int D[maxN][maxN][maxN] = {};

void upd(int i, int j, int k) {
	D[i][j][k] = n + 1;
	if (i > 0) D[i][j][k] = min(D[i][j][k], nxt[ D[i-1][j][k] ][ T[0][i-1] - 'a' ] + 1);
	if (j > 0) D[i][j][k] = min(D[i][j][k], nxt[ D[i][j-1][k] ][ T[1][j-1] - 'a' ] + 1);
	if (k > 0) D[i][j][k] = min(D[i][j][k], nxt[ D[i][j][k-1] ][ T[2][k-1] - 'a' ] + 1);

	assert(D[i][j][k] >= min(n+1, i+j+k));
}

void run() {
	cin >> n >> q >> S;

	// preprocess S
	REP(i, 26) nxt[n][i] = n;
	REP(i, 26) nxt[n+1][i] = n;
	for (int i = n-1; i >= 0; i--) {
		REP(j, 26) nxt[i][j] = nxt[i+1][j];
		nxt[i][S[i] - 'a'] = i;
	}
	// nxt[i][ch] : index (0-based) of next character 'ch' or this position

	REP(i, maxN) REP(j, maxN) REP(k, maxN) D[i][j][k] = n+1; // not possible.
	D[0][0][0] = 0; // empty seq.

	while (q--) {
		char op; int idx;
		cin >> op >> idx;
		idx--;

		if (op == '-') {
			T[idx].pop_back();
			N[idx]--;
		} else {
			cin >> op;
			T[idx].pb(op);
			N[idx]++;

			// now add DP states using this character.
			if (idx == 0)
				for (int jk = 0; jk <= N[1] + N[2]; jk++)
					for (int j = max(0, jk - N[2]); j <= min(jk, N[1]); j++)
						upd(N[0], j, jk - j);
			else if (idx == 1)
				for (int ik = 0; ik <= N[0] + N[2]; ik++)
					for (int i = max(0, ik - N[2]); i <= min(ik, N[0]); i++)
						upd(i, N[1], ik - i);
			else
				for (int ij = 0; ij <= N[0] + N[1]; ij++)
					for (int i = max(0, ij - N[1]); i <= min(ij, N[0]); i++)
						upd(i, ij - i, N[2]);
		}

		if (D[N[0]][N[1]][N[2]] <= n)
			printf("YES\n");
		else printf("NO\n");

		/*
		if (op == '-')
			T[idx].pop_back();
		} else {
			cin >> op;
			T[idx].pb(op);
		}

		int pos = 0;
		bool poss = true;
		vi I(4, 0), N(4, 0);
		for (int i=1; i<=3; i++) N[i] = (int) T[i].size();

		while (I[1] < N[1] || I[2] < N[2] || I[3] < N[3]) {
			int i = I[1] == N[1] ? n : nxt[pos][ T[1][I[1]] - 'a'];
			int j = I[2] == N[2] ? n : nxt[pos][ T[2][I[2]] - 'a'];
			int k = I[3] == N[3] ? n : nxt[pos][ T[3][I[3]] - 'a'];

			int m = min(i, min(j, k));
			if (m >= n) { poss = false; break; }

			cerr << "now " << m << " " << i << " " << j << " " << k << endl;

			if (m == i) {
				I[1]++;
			} else if (m == j) {
				I[2]++;
			} else {
				I[3]++;
			}
			pos = m + 1;
		}

		assert(poss == (I[1] == N[1] && I[2] == N[2] && I[3] == N[3]));
		if (poss) printf("YES\n");
		else printf("NO\n"); */
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	run();
	return 0;
}