
// Problem : B. Combinatorics Homework
// Contest : Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1574/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

void main_() {
	int a, b, c, m;
	cin >> a >> b >> c >> m;
	
	int mx = a + b + c - 3;
	int mn;
	
	if (a >= b && a >= c) {
		mn = max(a - b - c - 1, 0);
	} else if (b >= a && b >= c) {
		mn = max(b - a - c - 1, 0);
	} else {
		mn = max(c - a - b - 1, 0);
	}
	
	if (mn <= m && m <= mx) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}