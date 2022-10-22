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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int t;
int n = 8;

int dir;
int r, c;
char tmp[20];
string s;
int move(int nr, int nc) {
	r = nr, c = nc;
	printf("%d %d\n", nr, nc);
	fflush(stdout);
	scanf(" %s", tmp);
	s = tmp;
	if (s.find("Done") != string::npos) {
		return 1;
	} else if (s.find("Down") != string::npos) {
		if (move(nr + 1, nc) == 1) return 1;
		return 0;
	} else if (s.find("Up") != string::npos) {
		if (c != 1) {
			dir = 1;
			return move(r, 1);
		} else if (c != n) {
			dir = -1;
			return move(r, n);
		} else {
			assert(0);
		}
	} else {
		return -1;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		printf("1 1\n");
		fflush(stdout);
		r = c = 1;
		scanf(" %s", tmp);
		s = tmp;
		if (s == "Done") {
			continue;
		}
		dir = 1;
		while (1) {
			int res;
			int end = dir == 1 ? n : 1;
			if (c != end) {
				res = move(r, c + dir);
			} else {
				res = move(r + 1, c);
				dir *= -1;
			}
			if (res == 1) { // DONE
				break;
			}
			if (res == 0) { // DOWN
				if (c != 1 && c != n) {
				   	if (move(r, 1) == 1) {
						break;
					}
				}
				if (c == 1) {
					dir = 1;
				} else if (c == n) {
					dir = -1;
				}
			} 
		}
	}
	return 0;
}