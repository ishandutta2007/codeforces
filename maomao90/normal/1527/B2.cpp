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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 1005

int t;
int n;
char s[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		int mid = n / 2;
		int cnt = 0;
		REP (i, 0, n) {
			if (s[i] == '0') cnt++;
		}
		int mis = 0;
		REP (i, 0, n / 2) {
			if (s[i] != s[n - i - 1]) mis++;
		}
		int a = 0, b = 0;
		int start = 0;
		b += mis;
		cnt -= mis;
		if (cnt != 0) {
			if (cnt == 1) {
				a++;
			} else if (n % 2 == 1 && s[mid] == '0') {
				b++;
			} else {
				if (mis != 0) {
					b--;
					a++;
					b += 2;
				} else {
					a += 2;
				}
			}
		}
		if (a < b) {
			printf("ALICE\n");
		} else if (a == b) {
			printf("DRAW\n");
		} else {
			printf("BOB\n");
		}
	}
	return 0;
}