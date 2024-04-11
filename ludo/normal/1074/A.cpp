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

const int maxn = 1e5 + 10;
int N, M;
int X[maxn], Y[maxn];
int nrem[maxn] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	REP(i, N) cin >> X[i];

	int minR = 1000 * 1000 * 1000;
	X[N++] = minR;

	sort(X, X + N);
	REP(i, N) minR = min(minR, X[i]);

	for (int i = 0; i < M; ) {
		int l, r;
		cin >> l >> r >> Y[i];

		if (l > 1 || r < minR) {
			// we can by-pass this.
			M--;
		} else {
			// blocked by some X[i]

			// l == 1 && r >= minR
			int idx = upper_bound(X, X + N, r) - X;
			//  assert(idx > 0);
			nrem[idx - 1]++;

			i++;
		}
	}

	int ret = M;
	int nleft = M;
	for (int i = 0; i + 1 < N; i++) {
		nleft -= nrem[i]; // do not bother the horizontal
		nleft++; // break down this vertical
		ret = min(ret, nleft);
	}
	cout << ret << endl;

	return 0;
}