// time-limit: 2000
// problem-url: https://codeforces.com/contest/1617/problem/B

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

int n;

int main() {
	int _t = 1;
   	scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			// b = a + 1
			// a + a + 2 = n
			// a + 1 = n / 2
			int a = n / 2 - 1;
			printf("%d %d %d\n", a, a + 1, 1);
		} else {
			// b = a + 2
			// a + a + 3 = n
			// a = n - 3 / 2
			int a = (n - 3) / 2;
			int b = a + 2;
			if (a % 2 == 0) {
				a = (n - 5) / 2;
				b = a + 4;
			}
			printf("%d %d %d\n", a, b, 1);
		}
	}
	return 0;
}