// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/E

// he refreshes my soul. He guides me along the right
// paths for his name's sake
// Psalms 23:3
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
#define MAXN 200005

int q;
int n;
char s[MAXN], t[MAXN];
set<int> st[30];

int fw[MAXN];
void incre(int i, int x) {
	for (; i <= n; i += i & -i) fw[i] += x;
}
int qsm(int i) {
	int res = 0;
	for (; i > 0; i -= i & -i) res += fw[i];
	return res;
}
int qsm(int s, int e) {
	return qsm(e) - qsm(s - 1);
}

int orig;
int nxt(int i, int j) {
	while (!st[j].empty() && *st[j].begin() + qsm(*st[j].begin(), n) < i) {
		st[j].erase(st[j].begin());
	}
	if (st[j].empty()) {
		return n + 1;
	} else {
		orig = *st[j].begin();
		return *st[j].begin() + qsm(*st[j].begin(), n);
	}
}

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		scanf(" %s", s + 1);
		scanf(" %s", t + 1);
		REP (i, 0, n + 5) {
			fw[i] = 0;
		}
		REP (i, 0, 30) {
			st[i].clear();
		}
		REP (i, 1, n + 1) {
			st[s[i] - 'a'].insert(i);
		}
		ll cur = 0;
		ll ans = LINF;
		REP (i, 1, n + 1) {
			int mn = INF;
			REP (j, 0, t[i] - 'a') {
				mnto(mn, nxt(i, j));
			}
			if (mn <= n) {
				mnto(ans, cur + (mn - i));
			}
			mn = nxt(i, t[i] - 'a');
			debug("%d: %d\n", i, mn);
			if (mn > n) {
				break;
			}
			cur += (mn - i);
			incre(orig, 1);
			st[t[i] - 'a'].erase(orig);
		}
		if (ans != LINF) {
			printf("%lld\n", ans);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}