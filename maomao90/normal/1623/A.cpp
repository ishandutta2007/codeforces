// time-limit: 1000
// problem-url: https://codeforces.com/contest/1623/problem/A

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

int t;
int n, m, r1, c1, r2, c2;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d", &n, &m, &r1, &c1, &r2, &c2);
		int a = r2 - r1, b = c2 - c1;
		if (a < 0) {
			a = n - r1 + n - r2;
		}
		if (b < 0) {
			b = m - c1 + m - c2;
		}
		printf("%d\n", min(a, b));
	}
	return 0;
}