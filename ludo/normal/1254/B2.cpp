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

ll minimize(const vector< pair<ll, ll> > &pos) {
	// pos = { (x,#) }

	ll sum_nr = 0;
	for (auto pr : pos) sum_nr += pr.y;
	sum_nr /= 2;
	
	ll loc = -1;
	for (auto pr : pos) {
		sum_nr -= pr.y;
		if (sum_nr < 0) {
			loc = pr.x;
			break;
		}
	}

	ll ret = 0;
	for (auto pr : pos)
		ret += abs(pr.x - loc) * pr.y;
	return ret;
}

ll Try(const vi &A, ll p) {
	int n = sz(A);
	ll sum = 0;

	vector< pair<ll,ll> > cur_nr = {};
	ll cursum = 0;
	REP(i, n) {
		if (A[i] == 0) continue;

		ll rem = p - (cursum);
		if (A[i] <= rem) {
			cursum += A[i];
			cur_nr.eb(i, A[i]);
			// assert(cursum <= p);
			if (p == cursum) {
				sum += minimize(cur_nr);
				cur_nr.clear();
				cursum = 0;
			}
		} else {
			cursum += rem;
			cur_nr.eb(i, rem);
			// assert(cursum == p);
			ll A_left = (A[i] - rem) % p;

			sum += minimize(cur_nr);
			cur_nr.clear();
			cursum = A_left; 

			cur_nr.eb(i, A_left);
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

	ll sum = 0;
	REP(i, n) sum += A[i];

	vector<ll> pr_divs;
	for (ll i = 2; i*i <= sum; i++) {
		if (sum % i != 0) continue;
		while (sum % i == 0) sum /= i;

		pr_divs.pb(i);
	}
	if (sum > 1) pr_divs.pb(sum);

	ll answer = LLONG_MAX;
	for (ll p : pr_divs) {
		answer = min(answer, Try(A, p));
		// cerr << p << ": " << Try(A, p) << endl;
	}

	if (answer == LLONG_MAX)
		answer = -1;
	cout << answer << endl;
	return 0;
}