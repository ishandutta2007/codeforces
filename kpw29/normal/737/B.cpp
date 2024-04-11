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
#define maxn 1000100
int n, m, k, a, b, c;

int main() {
	boost;
	string s;
	cin >> n >> a >> b >> k;
	cin >> s;
	int sum = 0;
	vector <int> shots;
	shots.clear();
	
	FOR(i, 0, n-1) {
		if (s[i] == '1') sum = 0;
		else {
			++sum;
			if (sum == b) {
				shots.pb(i);
				sum = 0;
			}
		}
	}
	int sz = (int)shots.size();
	sz -= (a - 1);
	if (sz == 0) {
		cout << 1 << endl;
		FOR(i, 0, n-1)
		 if (s[i] == '0') {
			 cout << i + 1;
			 exit(0);
		 }
	}
	cout << sz << endl;
	for (int i=1; i<=sz; ++i) cout << shots[i - 1] + 1 << ' ';
}