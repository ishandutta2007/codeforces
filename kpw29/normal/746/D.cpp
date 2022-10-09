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
	cin >> n >> k >> a >> b;
	int last = 0, cnt = 0;
	string s = "";
	FOR(i, 1, n) {
		if (a > b && (last != 1 || cnt != k)) {
			if (last == 1) ++cnt;
			else cnt = 1;
			last = 1;
			if (a == 0) OUT("NO");
			a--;
			s += 'G';
		}
		else if (last != -1 || cnt != k) {
			if (last == -1) ++cnt;
			else cnt = 1;
			last = -1;
			if (b == 0) OUT("NO");
			b--;
			s += 'B';
		}
		else {
			if (last == 1) ++cnt;
			else cnt = 1;
			last = 1;
			if (a == 0) OUT("NO");
			a--;
			s += 'G';
		}
	}
	cout << s;
}