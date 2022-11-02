#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll minimize(const vi &pos) {
	ll ret = 0;
	int mid_pos = pos[sz(pos)/2];
	for (int x : pos)
		ret += abs(x - mid_pos);
	return ret;
}

ll Try(const vi &A, int p) {
	int n = sz(A);
	ll sum = 0;

	vi cur_nr = {};
	REP(i, n) {
		if (A[i]) {
			cur_nr.pb(i);
			if (sz(cur_nr) == p) {
				sum += minimize(cur_nr);
				cur_nr.clear();
			}
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vi A(n);
	REP(i, n) cin >> A[i];

	int sum = accumulate(all(A), 0);

	vi pr_divs;
	for (int i = 2; i*i <= sum; i++) {
		if (sum % i != 0) continue;
		while (sum % i == 0)
			sum /= i;

		pr_divs.pb(i);
	}
	if (sum > 1) pr_divs.pb(sum);

	ll answer = LLONG_MAX;
	for (int p : pr_divs) {
		answer = min(answer, Try(A, p));
	}

	if (answer == LLONG_MAX)
		answer = -1;
	cout << answer << endl;
	return 0;
}