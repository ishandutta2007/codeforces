#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, a, b, x;
string s[55];
void solve () {
	cin >> n;
	a = b = x = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (char c : s[i]) {
			if (c == '0') a++;
			else b++;
		}
		x += s[i].size() % 2;
	}

	cout << n - 1 + (a % 2 + b % 2 <= x) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}