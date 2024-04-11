#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

ll n, m, k, a, b, c;
ll t[5];

int main() {
	FOR(i, 0, 3) cin >> t[i];
	ll wyn = min(t[0], t[2]);
	wyn = min(wyn, t[3]);
	ll ret = wyn * 256;
	t[0] -= wyn; t[2] -= wyn; t[3] -= wyn;
	wyn = min(t[0], t[1]);
	ret += 32 * wyn;
	cout << ret;
}