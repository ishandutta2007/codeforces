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
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
		<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
};


bool palindrome(const string &str, int len)
{
	for (int i=0, j = len-1; i < j; i++, j--)
		if (str[i] != str[j]) return false;
	return true;
}

string run(string &str) {
	int n = (int) str.size();

	int L = 0, R = n-1;
	while (L <= R && str[L] == str[R]) L++, R--;

	// palindrome!
	if (L > R) return str;
	assert(L < R);

	string ls, rs;
	for (int i = L; i <= R; i++) ls += str[i];
	for (int i = R; i >= L; i--) rs += str[i];

	int mid = R - L + 1;

	assert(ls.size() == mid);
	assert(rs.size() == mid);

	// cerr << ls << " " << rs << endl;

	string lls = "";
	for (int len = mid; len >= 1; len--) {
		if (palindrome(ls, len)) {
			lls = ls.substr(0, len);
			break;
		}
	}

	string rrs = "";
	for (int len = mid; len >= 1; len--) {
		if (palindrome(rs, len)) {
			rrs = rs.substr(0, len);
			break;
		}
	}
	reverse(all(rrs));

	// cerr << lls << " " << rrs << endl;

	string res;
	for (int i=0; i<L; i++) res += str[i];

	if (lls.size() > rrs.size())
		res += lls;
	else
		res += rrs;

	// in between...

	for (int i=R; ++i < n; ) res += str[i];

	return res;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int t;
	cin >> t;
	while (t--) {
		string in;
		cin >> in;
		string out = run(in);
		printf("%s\n", out.c_str());
	}
	return 0;
}