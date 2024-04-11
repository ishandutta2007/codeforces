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
#define MAXN 105

int n;
int q[MAXN];
int nxt[MAXN];
int used[MAXN];

int ask() {
	printf("?");
	REP (i, 1, n + 1) {
		printf(" %d", q[i]);
	}
	printf("\n");
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

int main() {
	scanf("%d", &n);
	RREP (i, n, 1) {
		REP (j, 1, i) {
			q[j] = 2;
		}
		q[i] = 1;
		REP (j, i + 1, n + 1) {
			q[j] = 2;
		}
		int x = ask();
		if (x != 0 && x != i) {
			nxt[x] = i;
		}
		REP (j, 1, n + 1) {
			q[j] = 1;
		}
		q[i] = 2;
		x = ask();
		if (x != 0 && x != i) {
			nxt[i] = x;
		}
	}
	REP (i, 1, n + 1) {
		used[nxt[i]] = 1;
	}
	int rt = -1;
	REP (i, 1, n + 1) {
		if (!used[i]) {
			assert(rt == -1);
			rt = i;
			break;
		}
	}
	q[rt] = 1;
	while (rt != 0) {
		q[nxt[rt]] = q[rt] + 1;
		rt = nxt[rt];
	}
	printf("!");
	REP (i, 1, n + 1) {
		printf(" %d", q[i]);
	}
	printf("\n");
	return 0;
}