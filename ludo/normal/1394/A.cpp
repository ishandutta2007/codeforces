#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) begin(v), end(v)
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
		<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

namespace std { template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
}; }

void run() {
	ll n, d, m;
	cin >> n >> d >> m;

	vector<ll> A, B;
	REP(i, n) {
		ll x;
		cin >> x;
		if (x > m) A.pb(x);
		else B.pb(x);
	}

	sort(all(A));
	sort(all(B));

	vector<ll> pA(A.size()+1,0), pB(B.size()+1,0);
	REP(i, A.size()) pA[i+1] = pA[i] + A[i];
	REP(i, B.size()) pB[i+1] = pB[i] + B[i];

	ll res = 0;
	if (A.empty()) res = pB[B.size()];

	for (ll leaveA = 1; leaveA <= A.size(); leaveA++) {
		// leaveA = nr of elements in A which we leave inside the array.
		ll nrDrop = ll(d) * (leaveA-1); // we put one at the end for sure.
		ll takeA = A.size() - leaveA;
		ll takeB = nrDrop - takeA; // = nrDrop - A.size() + leave

		if (takeB < 0 && takeB >= -d) takeB = 0;

		// cerr << leaveA << ": " << takeA << " " << takeB << endl;
		if (takeA < 0 || takeA > A.size() || takeB < 0 || takeB > B.size())
			continue;

		ll alt = (pB[B.size()] - pB[takeB])
			   + (pA[A.size()] - pA[takeA]);

		// cerr << leaveA << ": " << takeA << " " << takeB << " -> " << alt << endl;

		res = max(res, alt);
	}
	cout << res << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	// int T; cin >> T; REP(i, T) run(i);
	run();
	return 0;
}