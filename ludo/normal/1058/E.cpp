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

const int maxn = 3e5 + 10;
const int maxbits = 64;

int N, a[maxn];
int waysl[2][maxbits][2] = {};
int waysr[maxn][maxbits][2] = {};

ll run()
{
	waysr[N - 1][0][0]++; // empty sequence
	for (int i = N - 1; i > 0; i--) {
		bool par = a[i] & 1;
		// use i, to construct i + 1
		// we are forced to pick a[i]

		// maximum is now a[i]
		for (int j = 0; j <= a[i]; j++) {
			waysr[i - 1][a[i]][0] += waysr[i][j][par];
			waysr[i - 1][a[i]][1] += waysr[i][j][!par];
		}
		for (int j = a[i] + 1; j < maxbits; j++) {
			waysr[i - 1][j][0] = waysr[i][j][par];
			waysr[i - 1][j][1] = waysr[i][j][!par];
		}
		// start the sequence at a[i]
		waysr[i - 1][0][0]++;
	}

	// parity: even
	waysl[0][0][0]++; // empty sequence

	ll ret = 0;
	// count sequences
	REP(i, N) {
		int cur = i & 1, lst = ~i & 1;

		// get from left.
		int par = a[i] & 1;

		ll sl1 = 0, sl2 = 0;
		REP(j, a[i]) {
			sl1 += waysl[cur][j][0];
			sl2 += waysl[cur][j][1];
		}
		ll sr1 = 0, sr2 = 0;
		for (int j = 0; j <= a[i]; j++) {
			sr1 += waysr[i][j][par];
			sr2 += waysr[i][j][!par];
		}

		ll w1 = sl1 * sr1;
		ll w2 = sl2 * sr2;

		ret += w1;
		ret += w2;

//		cerr << i << ": " << sl1 << " " << sr1 << " + " << sl2 << " " << sr2 << endl;

		// remove wrong ones with sum < 2 * a[i]
		// sum - a[i] < a[i]
		for (int j = i, pf = 0; j >= 0 && pf < a[i]; pf += a[--j]) {
			// [j, ..., i, ..., k]
			for (int k = i, sm = pf; k < N && sm < a[i]; sm += a[++k]) {
				if (!((sm + a[i]) & 1)) {
//					cerr << "DENY " << j << " - " << k << endl;
					// even:
					ret--;
				}
			}
		}

		// use i, to construct i + 1
		// we are forced to pick a[i]

		for (int j = 0; j < a[i]; j++)
			waysl[lst][j][0] = waysl[lst][j][1] = 0;

		waysl[lst][a[i]][par] = waysl[cur][a[i]][0] + sl1;
		waysl[lst][a[i]][!par] = waysl[cur][a[i]][1] + sl2;

		for (int j = a[i] + 1; j < maxbits; j++) {
			waysl[lst][j][0] = waysl[cur][j][par];
			waysl[lst][j][1] = waysl[cur][j][!par];
		}
		// start an empty sequence again:
		waysl[lst][0][0]++;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	REP(i, N) {
		ll X;
		cin >> X;
		a[i] = __builtin_popcountll(X);
	}

#ifdef DEBUG
	REP(i, N) cerr << a[i] << " ";
	cerr << endl;
#endif

	ll ret = run();
	cout << ret << endl;
	return 0;
}