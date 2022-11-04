
// Problem : D. Make a Power of Two
// Contest : Codeforces - Codeforces Round #739 (Div. 3)
// URL : https://codeforces.com/contest/1560/problem/D
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

string n;

void solve () {
	cin >> n;
	
	int res = 1e9;
	for (ll i = 1; i <= 2e18; i *= 2) {
		string x = to_string(i);
		
		int p = 0;
		for (int j = 0, k = 0; j < n.size();) {
			if (k < x.size() && n[j] == x[k]) {
				j++, k++;
			} else {
				p++;
				j++;
			}
			
			if (j == n.size()) {
				p += int(x.size()) - k;
			}
		}
		
		res = min(res, p);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}