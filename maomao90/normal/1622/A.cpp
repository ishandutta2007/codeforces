// time-limit: 2000
// problem-url: https://codeforces.com/contest/1622/problem/A

// Dear friends, since God so loved us, we also ought to love one another
// 1 John 4:11
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

int main() {
	scanf("%d", &t);
	while (t--) {
		int a[4];
		REP (i, 0, 3) {
			scanf("%d", &a[i]);
		}
		sort(a, a + 3);
		if (a[0] + a[1] == a[2]) {
			printf("YES\n");
		} else {
			if (a[1] == a[2]) {
				swap(a[0], a[2]);
			}
			if (a[0] == a[1]) {
				if (a[2] % 2 == 0) {
					printf("YES\n");
					continue;
				}
			}
			printf("NO\n");
		}
	}
	return 0;
}