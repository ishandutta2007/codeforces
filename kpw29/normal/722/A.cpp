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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ld, ld> PLD;
typedef pair <PLD, ld> PLDD;
typedef pair <PLL, ll> PLLL;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const long long INF = (ll)1e18+3;
int n, m, a, b, c, DL = 0, CC = 0, T;
#define maxn 110
int t[maxn], k[maxn];
string s;
string wyn;
int main() {
	int a, b;
	int pod;
	cin >> pod >> s;
	wyn = s;
	a = 10 * (s[0] - '0') + s[1] - '0';
	b = 10 * (s[3] - '0') + s[4] - '0';
	
	if (b >= 60) wyn[3] = '0';
	
	if (pod == 12) {
		if (a == 0 || a > 12) {
			if (s[1] == '0') wyn[0] = '1';
			else wyn[0] = '0';
		}
	}
	else if (a >= 24) wyn[0] = '0';
	cout << wyn;
}