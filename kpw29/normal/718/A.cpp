#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18;
int n, m, k, zap, a, b, c, jest, CC = 0, T;
#define maxn 1000100

string s;

void repair(int place) {
	if (place == -1) {
		cout << 1;
		FOR(i, 0, jest - 1) cout << 0;
		exit(0);
	}
	if (s[place] == '.') {
		repair(place - 1);
		return;
	}
	
	if (s[place] == '9') {
		repair(place - 1);
		return;
	}
	
	s[place]++;
	if (place < jest) {
		FOR(i, 0, place) cout << s[i];
		FOR(i, place + 1, jest - 1) cout << 0;
		exit(0);
	}
	if (place > jest) {
		FOR(i, 0, place) cout << s[i];
		exit(0);
	}
	
}
int main() {
	boost;
	cin >> n >> T;
	cin >> s;
	if (T == 0) {
		FOR(i, 0, n-1) cout << s[i];
		exit(0);
	}
	jest = -1;
	FOR(i, 0, n-1) {
		if (s[i] == '.') jest = i;
		else {
			if (jest != -1 && s[i] > '4') {
				int st = i - 1;
				while (s[st] == '4') --st;
				++st;
				int length = i + 1 - st;
				length = min(T, length);
				st = i + 1 - length;
				repair(st - 1);
			}

		}
	}
	
	FOR(i, 0, n-1) cout << s[i];
	
}