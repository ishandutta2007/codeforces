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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1000005

const int dirr[] = {1, 0, -1, 0, 1, 1, -1, -1}, dirc[] = {0, 1, 0, -1, 1, -1, 1, -1};

int n, m;
char tmp[MAXN];
vector<string> grid;
vector<vi> psum;

int sum(int ur, int uc, int vr, int vc) {
	int res = psum[vr][vc];
	if (ur != 0) {
		res -= psum[ur - 1][vc];
	}
	if (uc != 0) {
		res -= psum[vr][uc - 1];
	}
	if (ur != 0 && uc != 0) {
		res += psum[ur - 1][uc - 1];
	}
	return res;
}

vector<vi> d;
queue<ii> q;
bool isPos(int x) {
	ll sze = (ll) (x + x + 1) * (x + x + 1);
	d.clear();
	REP (i, 0, n) {
		vi v;
		REP (j, 0, m) {
			v.pb(INF);
		}
		d.pb(v);
	}
	REP (i, 0, n) {
		REP (j, 0, m) {
			int ur = i - x, uc = j - x, vr = i + x, vc = j + x;
			if (ur < 0 || uc < 0 || vr >= n || vc >= m) continue;
			if (sum(ur, uc, vr, vc) == sze) {
				d[i][j] = 0;
				q.push(MP(i, j));
			}
		}
	}
	while (!q.empty()) {
		auto [ur, uc] = q.front(); q.pop();
		REP (i, 0, 8) {
			int vr = ur + dirr[i], vc = uc + dirc[i];
			if (vr < 0 || vc < 0 || vr >= n || vc >= m) continue;
			if (mnto(d[vr][vc], d[ur][uc] + 1)) {
				q.push(MP(vr, vc));
			}
		}
	}
	REP (i, 0, n) {
		REP (j, 0, m) {
			if (grid[i][j] == 'X' && d[i][j] > x) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		scanf(" %s", tmp);
		string s = tmp;
		grid.pb(s);
		vi v;
		REP (j, 0, m) {
			if (s[j] == 'X') {
				v.pb(1);
			} else {
				v.pb(0);
			}
		}
		psum.pb(v);
	}
	REP (i, 0, n) {
		REP (j, 0, m) {
			if (i != 0) {
				psum[i][j] += psum[i - 1][j];
			}
			if (j != 0) {
				psum[i][j] += psum[i][j - 1];
			}
			if (i != 0 && j != 0) {
				psum[i][j] -= psum[i - 1][j - 1];
			}
		}
	}
	int lo = 0, hi = min(n, m), mid;
	while (lo < hi) {
		mid = lo + hi + 1 >> 1;
		if (isPos(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	isPos(lo);
	printf("%d\n", lo);
	REP (i, 0, n) {
		REP (j, 0, m) {
			if (d[i][j] == 0) {
				printf("X");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}