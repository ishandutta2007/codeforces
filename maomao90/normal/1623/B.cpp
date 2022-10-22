// time-limit: 1000
// problem-url: https://codeforces.com/contest/1623/problem/B

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
#define MAXN 1005

int t;
int n;
ii lr[MAXN];
bool used[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			int l, r; scanf("%d%d", &l, &r);
			lr[i] = MP(l, r);
		}
		sort(lr, lr + n, [] (ii l, ii r) {
				return l.SE - l.FI < r.SE - r.FI;
				});
		memset(used, 0, sizeof used);
		REP (i, 0, n) {
			int id = -1;
			REP (j, lr[i].FI, lr[i].SE + 1) {
				if (!used[j]) {
					id = j;
					break;
				}
			}
			assert(id != -1);
			used[id] = 1;
			printf("%d %d %d\n", lr[i].FI, lr[i].SE, id);
		}
		printf("\n");
	}
	return 0;
}