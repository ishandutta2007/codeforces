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
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf =1e9+9;
const ll mod = 1e9+9;
const ll MOD = 1e9+696969;
int n, m, k, a, b,maks, DL = 0, CC = 0, T;
#define maxn 100100
deque <char> w;

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) {
		char zn;
		cin >> zn;
		if (i & 1) w.push_back(zn);
		else w.push_front(zn);
	}
	string s = "";
	for (auto u : w) s += u;
	if (n % 2 == 0) reverse(s.begin(), s.end());
	cout << s;
}