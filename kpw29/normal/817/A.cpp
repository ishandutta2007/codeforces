#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
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
int n, k, a, b, c, d, x, y, DL = 0, T;
#define maxn 1000100


int main()
{
	cin >> a >> b >> c >> d >> x >> y;
	int dx = c - a, dy = d - b;
	dx = abs(dx); dy = abs(dy);
	if (dx % x != 0) OUT("NO");
	ll R = (dx / x);
	ll NY = abs(R * y - dy);
	if (NY % (2 * y) != 0) OUT("NO");
	OUT("YES"); 
}