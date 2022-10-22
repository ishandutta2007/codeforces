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
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n;
set<ii> st;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		int k, b; scanf("%d%d", &k, &b);
		if (k == 0) continue;
		int tp = -b, bt = k;
		int g = __gcd(abs(tp), abs(bt));
		tp /= g; bt /= g;
		if (tp < 0) {
			tp *= -1;
			bt *= -1;
		} else if (tp == 0) {
			bt = 0;
		}
		st.insert(MP(tp, bt));
	}
	printf("%d\n", (int) st.size());
	return 0;
}