#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 103

int n, m, a, b, c, d, T, st;

int askQuery(int x, int y) { //czy element x jest mniejszy od y
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char zn;
	cin >> zn;
	if (zn == '<') return -1;
	if (zn == '>') return 1;
	if (zn == '=') return 0;
	return -1337;
}

void answer(int x, int y) {
	printf("! %d %d\n", x, y);
	fflush(stdout);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1) {
			answer(1, 1);
			continue;
		}
		int maks = 0, minks = 0;
		if (askQuery(1, 2) == -1) minks = 1, maks = 2;
		else minks = 2, maks = 1;
		
		for (int i=3; i<=n; i+=2) {
			if (i == n) {
				if (askQuery(i, minks) == -1) minks = i;
				if (askQuery(i, maks) == 1) maks = i;
			}
			else {
				int x, y;
				if (askQuery(i, i+1) == -1) x = i, y = i + 1;
				else x = i + 1, y = i;
				if (askQuery(x, minks) == -1) minks = x;
				if (askQuery(y, maks) == 1) maks = y;
			}
		}
		
		answer(minks, maks);
	}
}