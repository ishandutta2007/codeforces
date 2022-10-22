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
#define MAXN 400005

int n, w;
int a[MAXN], b[MAXN];
int da[MAXN], db[MAXN];
int z[MAXN];
vi v;
int ans;

int main() {
	scanf("%d%d", &n, &w);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
	}
	n--;
	REP (i, 0, n) {
		da[i] = a[i + 1] - a[i];
	}
	REP (i, 0, w) {
		scanf("%d", &b[i]);
	}
	w--;
	REP (i, 0, w) {
		db[i] = b[i + 1] - b[i];
	}
	REP (i, 0, w) {
		v.pb(db[i]);
	}
	v.pb(INF);
	if (w == 0) {
		printf("%d\n", n + 1);
		return 0;
	}
	REP (i, 0, n) {
		v.pb(da[i]);
	}
	REP (i, 1, v.size()) {
		int j = z[i - 1];
		while (j != 0 && v[j] != v[i]) {
			j = z[j - 1];
		}
		z[i] = j + (v[i] == v[j]);
		if (z[i] == w) ans++;
	}
	printf("%d\n", ans);
	return 0;
}