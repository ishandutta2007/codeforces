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

const ll sqrt3 = 4641;

ll N, K, M;

ll run()
{
	if (K < M) return -1;

	ll maxret = -1LL;
	// try z = 0 separately:
	if (M <= K && K <= M + M) {
		maxret = K - M + (N - M);
		if (K < M + M) maxret++;

		return maxret;
	}

	if (N <= sqrt3) {
		for (ll a = 0; a <= M; a++) {
			for (ll b = 0; b <= N - M; b++) {
				if (K >= M + a && (K - M - a) % (N + a + b) == 0) {
					// z = (K - M - a) / (N + a + b) >= 0
					maxret = max(maxret, a + b);
				}
				if (a > 0 && K + 1 >= M + a && (K + 1 - M - a) % (N + a + b) == 0) {
					// last one takes only 1
					maxret = max(maxret, a + b);
				}
			}
		}
		return maxret;
	}

	for (ll z = 1; z <= K / N; z++) {
		ll x = K - z * N - M;
		if (0 <= x && x <= z * N + M) {
			ll lb1 = (x - M + z) / (z + 1);
			ll lb2 = (x - M + z - 1) / z;
			ll lb = max(lb1, lb2);
			
			ll ub1 = x / z;
			ll ub2 = (N + x - M) / (z + 1);
			ll ub = min(ub1, ub2);
			if (lb <= ub) {
				maxret = max(maxret, ub);
			}
		}
		x++;
		if (0 <= x && x <= z * N + M) {
			ll lb1 = (x - M + z) / (z + 1);
			ll lb2 = (x - M + z - 1) / z;
			ll lb = max(lb1, lb2);
			
			ll ub1 = (x - 1) / z;
			ll ub2 = (N + x - M) / (z + 1);
			ll ub = min(ub1, ub2);
			if (lb <= ub) {
				maxret = max(maxret, ub);
			}
		}
	}
	return maxret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll L, R;
	cin >> N >> L >> R >> K;

	if (L <= R) M = R - L + 1;
	else M = R - L + N + 1;

	ll ans = run();
	cout << ans << endl;

	// cerr << M << " 1 extra" << endl;
	// cerr << (N - M) << endl;

	return 0;
}