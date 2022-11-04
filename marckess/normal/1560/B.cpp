
// Problem : B. Who's Opposite?
// Contest : Codeforces - Codeforces Round #739 (Div. 3)
// URL : https://codeforces.com/contest/1560/problem/B
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

int a, b, c;

void solve () {
	cin >> a >> b >> c;
	a--, b--, c--;
	
	if (a > b) swap(a, b);
	
	int n = 2 * (b - a);
	if (b >= n || c >= n || (b + n / 2) % n != a) {
		cout << -1 << endl;
		return;
	}
	
	cout << (c + n / 2) % n + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}