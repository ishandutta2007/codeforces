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

int N, K, A[maxn];
ll L;

void imp() { cout << "0" << endl; }

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K >> L;
	REP(i, N * K) cin >> A[i];
	sort(A, A + N * K);

	int nr_leq = upper_bound(A, A + N * K, A[0] + L) - A;

	if (nr_leq < N) {
		// not enough
		imp();
		return 0;
	} else if (K == 1) {
		ll ret = 0;
		REP(i, N) ret += (ll) A[i];
		cout << ret << endl;
		return 0;
	}

	int q = (nr_leq - N) / (K - 1);
	// int r = (nr_leq - N) % (K - 1);

	ll volumes = 0;
	for (int i = 0; i <= q; i++) {
		volumes += (ll) A[K * i];
	}
	for (int i = q + 1; i < N; i++) {
		int idx = nr_leq - (N - i);
		// idx < nr_leq
		// q (k - 1) <= nr_leq - N
		// q k <= nr_leq - N + q < nr_leq - N + (q + 1)

		// thus, q k < idx < nr_leq
		volumes += (ll) A[idx];
	}

	cout << volumes << endl;

	return 0;
}