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
int x, y;

int dist(int i, int j, int x, int y) {
	return abs(x - i) + abs(j - y);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		int d = (x + y);
		if (d % 2 == 1) {
			printf("-1 -1\n");
			continue;
		}
		bool found = 0;
		REP (i, 0, 105) {
			REP (j, 0, 105) {
				if ((i + j) == d / 2 && dist(i, j, x, y) == d / 2) {
					found = 1;
					printf("%d %d\n", i, j);
					break;
				}
			}
			if (found) {
				break;
			}
		}
		if (!found) {
			printf("-1 -1\n");
		}
	}
	return 0;
}