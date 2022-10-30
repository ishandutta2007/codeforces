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
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const ld PI = acos(-1.0);
template<class T> using min_queue =
		priority_queue<T, vector<T>, greater<T>>;
template<class T> int sz(const T &x) {
	return (int) x.size(); // copy the ampersand(&)!
}

template<class T> ostream& operator<<(ostream &os, vector<T> &v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

struct pairhash {
public:
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2> &p) const {
		size_t lhs = hash<T1>()(p.x);
		size_t rhs = hash<T2>()(p.y);
		return lhs ^ (rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
	}
};

const int MAXN = 1'000'000;
int input[MAXN];

void run() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &input[i]);
	}

	vector<ll> sum(n+1, 0);
	for (int i=0; i<n; i++)
		sum[i+1] = sum[i] + input[i];

	vector<int> s;
	s.pb(0);
	for (int k=1; k<=n; k++) {
		while (s.size() >= 2) {
			int i = s[s.size()-2];
			int j = s[s.size()-1];

			bool better = (sum[k]-sum[i])*(j-i) <= (sum[j]-sum[i])*(k-i);
			if (!better) break;
			s.pop_back();
		}
		s.pb(k);
	}

	for (int i=1; i < sz(s); i++) {
		ld avg = sum[ s[i] ] - sum[ s[i-1] ];
		avg /= (s[i] - s[i-1]);
		for (int j = s[i-1]; j < s[i]; j++) {
			printf("%.10Lf\n", avg);
		}
	}
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	run();
	return 0;
}