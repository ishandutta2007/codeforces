// time-limit: 1500
// problem-url: https://codeforces.com/contest/1616/problem/D

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
#define MAXN 50005

int t;
int n;
int a[MAXN];
ll p[MAXN];
int x;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &x);
		REP (i, 0, n) {
			a[i] -= x;
			p[i + 1] = a[i];
			p[i + 1] += p[i];
		}
		ll mx = -LINF;;
		int ans = n;
		REP (i, 2, n + 1) {
			mxto(mx, p[i - 2]);
			debug("%d: %lld %lld\n", i, p[i], mx);
			if (p[i] - mx < 0) {
				mx = -LINF;
				ans--;
				i++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}