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
#define MAXN 1005

int t;
int n, m;
char str[MAXN];
string ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		scanf(" %s", str);
		ans = str;
		mnto(m, n);
		while (m--) {
			string tmp = ans;
			REP (i, 0, n) {
				int l = -1;
				if (i != 0) l = ans[i - 1] - '0';
				int r = -1;
				if (i != n - 1) r = ans[i + 1] - '0';
				if ((l == 1 && r != 1) || (l != 1 && r == 1)) {
					tmp[i] = '1';
				} else {
					tmp[i] = ans[i];
				}
			}
			swap(ans, tmp);
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}