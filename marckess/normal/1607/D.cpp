
// Problem : D. Blue-Red Permutation
// Contest : Codeforces - Codeforces Round #753 (Div. 3)
// URL : https://codeforces.com/contest/1607/problem/D
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

const int MX = 200005;
int n, a[MX];

void main_() {
	cin >> n;
	vi x, y;
	
	forn (i, n) cin >> a[i];
	forn (i, n) {
		char c;
		cin >> c;
		
		if (c == 'B') x.pb(a[i]);
		if (c == 'R') y.pb(a[i]);
	}
	
	sort(all(x));
	sort(all(y), greater<int>());
	
	forn (i, x.size())
		if (x[i] < i + 1) {
			cout << "NO" << endl;
			return;
		}
	
	forn (i, y.size())
		if (y[i] > n - i) {
			cout << "NO" << endl;
			return;
		}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}