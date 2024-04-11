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

const int maxn = 1e6;

int N, K, D, A[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> D;
	REP(i, N) cin >> A[i];
	sort(A, A + N);

	vector<int> opts;
	opts.pb(0);

	REP(i, N) {
		int from = lower_bound(A, A + N, A[i] - D) - A;
		// A[idx] >= A[i] - D
		int to = i - K + 1;

		if (from > to) continue;

		auto it = lower_bound(all(opts), from);
		if (it != opts.end() && *it <= to) {
			opts.pb(i + 1); // one can start from (i + 1)
		}

		// box: [j, ..., i]
		// where from <= j <= to
		// i - j >= i - (i - K + 1) + 1 = K
	}

	bool ret = !opts.empty() && opts.back() == N;

	cout << (ret ? "YES" : "NO") << endl;

	return 0;
}