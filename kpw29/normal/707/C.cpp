#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, k, zap, DL;
#define maxn 1000100
bool mark[maxn];
int A[maxn], B[maxn], C[maxn];

int main() {
	ll a, b ,c;
	cin >> a;
	if (a <= 2) OUT(-1);
	if (a % 2 == 0) {
		ll m = (a / 2), n = 1;
		cout <<  m * m - n * n << ' ' << m * m + n * n;
	}
	else {
		ll m = (a + 1) / 2;
		ll n = a - m;
		cout << m * m + n * n << ' ' << 2 * m * n;
	}
}