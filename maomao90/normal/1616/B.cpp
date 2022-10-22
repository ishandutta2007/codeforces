// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/B

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
int n;
char s[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		int id = n - 1;
		REP (i, 0, n - 1) {
			if (s[i] < s[i + 1]) {
				id = i;
				break;
			}
		}
		string ans = "";
		REP (i, 0, id + 1) {
			ans += s[i];
		}
		RREP (i, id, 0) {
			ans += s[i];
		}
		mnto(ans, string(2, s[0]));
		printf("%s\n", ans.c_str());
	}
	return 0;
}