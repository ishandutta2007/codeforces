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
#define MAXN 500005

int n, d;
ii sa[MAXN];
bool useless[MAXN];
vii bck, frnt;

bool comp1(ii l, ii r) {
	if (l.SE == r.SE) return l.FI < r.FI;
	return l.SE < r.SE;
}

int main() {
	scanf("%d%d", &n, &d);
	REP (i, 0, n) {
		scanf("%d%d", &sa[i].FI, &sa[i].SE);
		if (sa[i].FI < d) {
			i--;
			n--;
		}
		mxto(sa[i].SE, d);
	}
	REP (i, 0, n) {
		if (sa[i].FI >= sa[i].SE) {
			swap(sa[i].FI, sa[i].SE);
			bck.pb(sa[i]);
		} else {
			frnt.pb(sa[i]);
		}
	}
	sort(ALL(frnt), comp1);
	sort(ALL(bck), comp1);
	int ptr = 0;
	int mx = -1;
	REP (i, 0, frnt.size()) {
		while (ptr < bck.size() && frnt[i].SE > bck[ptr].SE) {
			mxto(mx, bck[ptr].FI);
			ptr++;
		}
		if (mx > frnt[i].FI) {
			useless[i] = 1;
		}
	}
	int ans = bck.size();
	REP (i, 0, frnt.size()) {
		if (useless[i]) continue;
		if (frnt[i].FI >= d) {
			ans++;
			d = frnt[i].SE;
		}
	}
	printf("%d\n", ans);
	return 0;
}