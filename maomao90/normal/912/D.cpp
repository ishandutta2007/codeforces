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

int n, m, r, k;
priority_queue<tuple<ll, int, int, int>> pq;
ll res;
double ans;

ll calc(int i, int y) {
	return (ll) (min(i, n - r) - max(0, i - r + 1) + 1) * 
			(min(y, m - r) - max(0, y - r + 1) + 1);
}


int main() {
	scanf("%d%d%d%d", &n, &m, &r, &k);
	REP (i, 0, n) {
		int y = m / 2;
		pq.push(MT(calc(i, y), i, y, 1));
		if (y - 1 < m) pq.push(MT(calc(i, y - 1), i, y - 1, -1));
	}
	while (k--) {
		auto [sum, i, y, mult] = pq.top(); pq.pop();
		res += sum;
		y += mult;
		if (y >= 0 && y < m) {
			pq.push(MT(calc(i, y), i, y, mult));
		}
	}
	ans = (double) res / ((ll) (n - r + 1) * (m - r + 1));
	printf("%.9f\n", ans);
	return 0;
}