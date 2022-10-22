#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1000005

int n;
string s;
char tmp[MAXN];
vi arr;

const char cc = 'a' - 1; // smallest character - 1
const int p1 = 29, p2 = 31;
const ll m1 = 1000000007, m2 = 1000000009;
ll pow1[MAXN], pow2[MAXN];
void precom() {
	pow1[0] = pow2[0] = 1;
	REP (i, 1, n + 2) {
		pow1[i] = pow1[i - 1] * p1 % m1;
		pow2[i] = pow2[i - 1] * p2 % m2;
	}
}
struct hsh {
	ll v1 = 0, v2 = 0;
	vll pref1, pref2;
	int sze = 0;
	bool operator== (const hsh& o) const {
		return v1 == o.v1;
	}
	bool operator< (const hsh& o) const {
		return MP(v1, v2) < MP(o.v1, o.v2);
	}
	hsh() {}
	hsh(ll v1, ll v2, int sze): v1(v1), v2(v2), sze(sze) {}
	hsh(const string& s) {
		REP (i, 0, n) {
			insert(s[i]);
		}
	}
	// right is most significant
	void insert(char _c) {
		int c = _c - cc;
		v1 = (v1 + pow1[sze] * c) % m1;
		v2 = (v2 + pow2[sze] * c) % m2;
		pref1.pb(v1);
		pref2.pb(v2);
		sze++;
	}
	pll query(int s, int e) {
		ll res1 = pref1[e], res2 = pref2[e];
		if (s > 0) {
			res1 = (res1 - pref1[s - 1] + m1) % m1;
			res2 = (res2 - pref2[s - 1] + m2) % m2;
		}
		res1 = res1 * pow1[sze - e] % m1;
		res2 = res2 * pow2[sze - e] % m2;
		return MP(res1, res2);
	}
} cur;

bool isPos(int _) {
	int x = arr[_];
	REP (i, 1, n - x - 1) {
		if (cur.query(0, x) == cur.query(i, i + x)) return 1;
	}
	return 0;
}

int main() {
	scanf(" %s", tmp);
	s = tmp;
	n = s.size();
	precom();
	cur = hsh(s);
	REP (i, 0, n - 1) {
		if (cur.query(0, i) == cur.query(n - i - 1, n - 1)) {
			arr.pb(i);
		}
	}
	int lo = 0, hi = arr.size() - 1, mid;
	int res = -1;
	while (lo <= hi) {
		mid = lo + hi + 1 >> 1;
		if (isPos(mid)) {
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	if (res == -1) {
		printf("Just a legend\n");
	} else {
		REP (i, 0, arr[res] + 1) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}