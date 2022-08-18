#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)102;
const int P = 1004;
//const ll INF = (ll)1e18 + 41;
const ld INF = 1e9;
const ld EPS = 1e-8;
const ll MD = (ll)1e9 + 7;
bool D = false;

ld dp[N][N][P + 11];
vector<pair<int, int>> a;
int n;
ld C, T;

void mne(ld &a, ld b) {
	if (b < a) a = b;
}

void init_dp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int p = 0; p < P; p++) {
				dp[i][j][p] = 1e20 + 100500;
			}
		}
	}

	dp[0][0][0] = 0;
	for (int len = 0; len < n; len++) {
		for (int num = 0; num <= len; num++) {
		    ld f = pow(1.0 / 0.9, num + 1);
			for (int p = 0; p <= P; p++) {
				ld curDp = dp[len][num][p];
				if (curDp > 1e20) continue;

				mne(dp[len + 1][num][p], curDp);
				mne(dp[len + 1][num + 1][p + a[len].second], curDp + a[len].first * f);
			}
		}
	}
}

void solve() {
	cin >> n;
	cin >> C >> T;

	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;		
	}
	sort(a.rbegin(), a.rend());

	//cerr << "b dp" << endl;
	init_dp();
	//cerr << "dp" << endl;
	//cerr << dp[n][2][7] << endl;

	int ans = 0;
	for (int num = 1; num <= n; num++) {
		for (int p = P - 1; p > 0; p--) {
			ld tme = dp[n][num][p];
			ld ser = num * 10.0;

			ld aa = C;
			ld bb = C * (ser - T) + 1;
			ld cc = tme - T + ser;

			ld tt = max((ld)0.0, -bb / (2.0 * aa));
			ld val = aa * tt * tt + bb * tt + cc;
			if (val <= 0) {
				ans = max(ans, p);
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
#endif
	while (tst--) solve();
}