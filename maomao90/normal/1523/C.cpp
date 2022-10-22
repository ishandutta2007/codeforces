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

int t;
int n;
vector<vi> ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans.clear();
		vi cur;
		REP (i, 0, n) {
			int a; scanf("%d", &a);
			if (a == 1) {
				cur.pb(1);
			} else {
				while (!cur.empty() && cur.back() + 1 != a) {
					cur.pop_back();
				}
				cur.back() = a;
			}
			ans.pb(cur);
		}
		for (auto v : ans) {
			REP (i, 0, v.size()) {
				printf("%d", v[i]);
				if (i != v.size() - 1) {
					printf(".");
				}
			}
			printf("\n");
		}
	}
	return 0;
}