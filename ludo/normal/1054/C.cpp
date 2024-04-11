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

// typedef pair<ii, int> T;

const int maxn = 1000;

ii A[maxn];
int N;

struct BIT {
	int n; vi v;
	BIT(int _n) : n(_n), v(_n) {}
	void add(int i, int w) {
		while (i < n) v[i] += w, i += i & -i;
	}
	int query(int i) {
		int r = 0;
		while (i > 0) r += v[i], i -= i & -i;
		return r;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vi NL(N), NR(N);

	REP(i, N) cin >> NL[i];
	REP(i, N) cin >> NR[i];

	REP(i, N) {
		A[i].x = NL[i] + NR[i];
		A[i].y = i;
	}

	sort(A, A + N);

	int nsums = 0;
	for (int i = 0; i < N; i++) {
		nsums += (i == 0 || A[i].x != A[i - 1].x);
	}

	vi X(N);

	for (int i = 0; i < N; ) {
		X[A[i++].y] = nsums;
		while (i < N && A[i - 1].x == A[i].x)
			X[A[i++].y] = nsums;

		nsums--;
	}

	BIT l(N + 1);
	REP(i, N) {
		int nrl = i - l.query(X[i]);
		if (nrl != NL[i]) {
			cout << "NO" << endl; return 0;
		}
		l.add(X[i], 1);
	}
	BIT r(N + 1);
	for (int i = N; i--; ) {
		int nrr = (N - 1 - i) - r.query(X[i]);
		if (nrr != NR[i]) {
			cout << "NO" << endl; return 0;
		}
		r.add(X[i], 1);
	}

	cout << "YES" << endl;
	REP(i, N) cout << X[i] << " ";
	cout << endl;

	return 0;
}