
// Problem : B. Scenes From a Memory
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int k;
string s;

bool isPrime (int x) {
	if (x == 1) return 0;
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

void solve () {
	cin >> k >> s;
	
	forn (i, k)
		if (!isPrime(s[i] - '0')) {
			cout << 1 << endl << s[i] << endl;
			return;
		}
	
	forn (j, k)
		forn (i, j)
			if (!isPrime((s[i] - '0') * 10 + (s[j] - '0'))) {
				cout << 2 << endl << s[i] << s[j] << endl;
				return;
			}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}