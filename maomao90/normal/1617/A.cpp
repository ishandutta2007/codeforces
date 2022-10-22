// time-limit: 1000
// problem-url: https://codeforces.com/contest/1617/problem/A

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

char s[MAXN], t[MAXN];

int main() {
	int _t = 1;
	scanf("%d", &_t);
	while (_t--) {
		scanf(" %s", s);
		scanf(" %s", t);
		int n = strlen(s);
		bool hasa = 0;
		REP (i, 0, n) {
			hasa |= s[i] == 'a';
		}
		bool bad = strcmp(t, "abc") == 0 && hasa;
		sort(s, s + n, [&] (char l, char r) {
				if (bad) {
					if (l == 'b' && r == 'c') {
						return false;
					} else if (l == 'c' && r == 'b') {
						return true;
					}
				}
				return l < r;
		});
		REP (i, 0, n - 3) {
			if (s[i] == t[0] && s[i + 1] == t[1] && s[i + 2] == t[2]) {
				swap(s[i + 1], s[i + 2]);
			}
		}
		printf("%s\n", s);
	}
	return 0;
}