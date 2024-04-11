// time-limit: 4000
// problem-url: https://codeforces.com/contest/1617/problem/E

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
#define MAXN 200005
#define MAXL 30

int n;
int a[MAXN];

int cost(int a, int b) {
	int res = 0;
	while (a != b) {
		if (a < b) {
			swap(a, b);
		}
		res++;
		int lg = 0;
		if (a != 1) {
			lg = 32 - __builtin_clz(a - 1);
		}
		a = (1 << lg) - a;
	}
	return res;
}

int dfs(int u) {
	int res = -1, id = -1;
	REP (i, 1, n + 1) {
		if (i == u) {
			continue;
		}
		if (mxto(res, cost(a[u], a[i]))) {
			id = i;
		}
	}
	return id;
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	int u = dfs(1);
	int v = dfs(u);
	printf("%d %d %d\n", u, v, cost(a[u], a[v]));
	return 0;
}