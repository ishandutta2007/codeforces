// time-limit: 3000
// problem-url: https://codeforces.com/contest/1617/problem/D1

// She will give birth to a son, and you are to give him the name Jesus,
// because he will save his people from their sins.
// Matthew 1:21
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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 10005

struct hsh {
	size_t operator() (const iii& o) const {
		size_t res = 17;
		res = (res * 31 + get<0>(o)) % MOD;
		res = (res * 31 + get<1>(o)) % MOD;
		res = (res * 31 + get<2>(o)) % MOD;
		return res;
	}
};

unordered_map<iii, bool, hsh> mp;
int n;
vi ans;
int type[MAXN];

bool ask(int a, int b, int c) {
	if (a > b) {
		swap(a, b);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a > b) {
		swap(a, b);
	}
	if (mp.find(MT(a, b, c)) != mp.end()) return mp[MT(a, b, c)];
	printf("? %d %d %d\n", a + 1, b + 1, c + 1);
	fflush(stdout);
	int r; scanf("%d", &r);
	assert(r != -1);
	mp[MT(a, b, c)] = 1 - r;
	return 1 - r;
}

int main() {
	int _t = 1;
   	scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);
		ans.clear();
		REP (i, 0, n + 1) {
			type[i] = -1;
		}
		mp.clear();
		vi v[2];
		v[0].clear();
		v[1].clear();
		for (int i = 0; i < n; i += 3) {
			v[ask(i, i + 1, i + 2)].pb(i); 
			if (!v[0].empty() && !v[1].empty()) {
				break;
			}
		}
		assert(!v[0].empty() && !v[1].empty());
		int a = v[1][0], b = v[0][0];
		bool b1 = ask(a, a + 1, b), b2 = ask(a, a + 1, b + 1);
		if (b1 && b2) {
			type[a] = type[a + 1] = 1;
			bool b3 = ask(b, b + 1, a);
			if (!b3) {
				type[b] = 0;
				type[b + 1] = 0;			
			} else {
				bool b4 = ask(b + 1, b + 2, a);
				if (!b4) {
					type[b + 1] = 0;
					type[b + 2] = 0;
					type[b] = 1;
				} else {
					type[b] = 0;
					type[b + 2] = 0;
					type[b + 1] = 1;
				}
			}
		} else if (b1 && !b2) {
			type[b] = 1; type[b + 1] = 0;
		} else if (!b1 && b2) {
			type[b] = 0; type[b + 1] = 1;
		} else {
			type[a + 2] = 1; type[b] = type[b + 1] = 0;
		}
		int id[2] = {-1, -1};
		REP (i, 0, n) {
			if (type[i] != -1) {
				id[type[i]] = i;
			}
		}
		assert(id[0] != -1 && id[1] != -1);
		REP (i, 0, n) {
			if (type[i] != -1) continue;
			type[i] = ask(id[0], id[1], i);
		}
		REP (i, 0, n) {
			if (type[i]) {
				ans.pb(i);
			}
		}
		printf("! %d", (int) ans.size());
		for (int i : ans) {
			printf(" %d", i + 1);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}