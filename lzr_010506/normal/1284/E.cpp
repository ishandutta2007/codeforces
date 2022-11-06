#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define LD long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const LD pi = acos(-1);
const LD eps = 1e-16;
 
struct Point {
	long long px, py;
};
 
int shogen(Point V1) {
	if (V1.px == 0) {
		if (V1.py >= 0) return 1;
		return 3;
	}
	if (V1.py == 0) {
		if (V1.px >= 0) return 0;
		return 2;
	}
	if (V1.px > 0 && V1.py > 0) return 0;
	if (V1.px < 0 && V1.py > 0) return 1;
	if (V1.px < 0 && V1.py < 0) return 2;
	return 3;
}
 
bool operator<(const Point &a1, const Point &a2) {
	int c1 = shogen(a1), c2 = shogen(a2);
	if (c1 < c2) return true;
	if (c1 > c2) return false;
 
	// (3, 7) < (2, 5)
	if (a1.py * a2.px < a1.px * a2.py) return true;
	return false;
}
 
ll N, x[3010], y[3010], sum;
 
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
 
	for (int i = 0; i < N; i++) {
		vector<Point>vec;
		for (int j = 0; j < N; j++) { if (i == j) continue; vec.push_back(Point{ x[j] - x[i], y[j] - y[i] }); }
		sort(vec.begin(), vec.end());
		
		for (int j = 0; j < vec.size(); j++) {
			int pos1 = lower_bound(vec.begin(), vec.end(), Point{ -1LL * vec[j].px, -1LL * vec[j].py }) - vec.begin();
			long long A1 = pos1 - (j + 1); if (A1 < 0) A1 += vec.size();
			long long A2 = 1LL * vec.size() - 1LL - A1;
 
			sum += (A1 * (A1 - 1LL) / 2LL) + (A2 * (A2 - 1LL) / 2LL);
		}
	}
	sum /= 2;
	sum = (ll)N*(N-1)*(N-2)*(N-3)/6-sum;
	sum = (ll)sum*(N-4)/2;
	printf("%lld\n", sum);
	return 0;
}