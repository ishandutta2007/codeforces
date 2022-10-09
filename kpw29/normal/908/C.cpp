#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
const int maxn = 2010;
long double x[maxn], y[maxn];
long double r;

int n;
int main()
{
	boost;
	cin >> n >> r;
	FOR(i, 1, n) cin >> x[i];
	long double U = 4 * r * r;
	FOR(i, 1, n) {
		double xx = x[i];
		long double H = r;
		for (int j=1; j<i; ++j) {
			long double help = (xx - x[j]) * (xx - x[j]);
			if (help <= U) H = max(H, y[j] + sqrt(U - help));
		}
		y[i] = H;
	}
	
	FOR(i, 1, n) {
		cout << fixed;
		cout << setprecision(15);
		cout << y[i] << ' ';
	}
}