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


void manacher(const string &s, vi &pal) {
	int n = s.length(), i = 1, l, r;
	while (i < 2 * n + 1) {
		if ((i&1) && pal[i] == 0) pal[i] = 1;
		l = i / 2 - pal[i] / 2; r = (i-1) / 2 + pal[i] / 2;

		while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1])
			--l, ++r, pal[i] += 2;

		for (l = i - 1, r = i + 1; l >= 0 && r < 2 * n + 1; --l, ++r) {
			if (l <= i - pal[i]) break;
			if (l / 2 - pal[l] / 2 > i / 2 - pal[i] / 2)
				pal[r] = pal[l];
			else {	if (l >= 0)
					pal[r] = min(pal[l], i + pal[i] - r);
				break;
			}
		}
		i = r;
}	}



string run(const string &str) {
	int n = (int) str.size();

	int L = 0, R = n-1;
	while (L <= R && str[L] == str[R]) L++, R--;

	// palindrome!
	if (L > R) return str;
	// assert(L < R);

	string ls, rs;
	for (int i = L; i <= R; i++) ls += str[i];
	for (int i = R; i >= L; i--) rs += str[i];

	int mid = R - L + 1;

	vi lp(2*mid+1,0), rp(2*mid+1,0);
	manacher(ls, lp);
	manacher(rs, rp);

	int ml = 1, mr = 1;
	for (int i = 1; i <= mid; i++) if (lp[i] == i) ml = i;
	for (int i = 1; i <= mid; i++) if (rp[i] == i) mr = i;

	string lls = ls.substr(0, ml), rrs = rs.substr(0, mr);

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
	int t;
	cin >> t;
	while (t--) {
		string in;
		cin >> in;
		/* for (int i=0; i< 100'000; i++)
			buffer[i] = 'a' + (rand() % 2);
		buffer[100'000] = '\0'; */

		string out = run(in);
		printf("%s\n", out.c_str());
	}
	return 0;
}