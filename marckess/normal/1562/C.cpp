
// Problem : C. Rings
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/C
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

int n;
string s;

void ans (int l1, int r1, int l2, int r2) {
	cout << l1 + 1 << " " << r1 + 1 << " " << l2 + 1 << " " << r2 + 1
 << endl;
}

void solve () {
	cin >> n >> s;
	
	for (int i = n / 2; i < n; i++)
		if (s[i] == '0')
			return ans(i - n / 2, i, i - n / 2, i - 1);
	
	if (s[n / 2 - 1] == '0') {
		return ans(n / 2 - 1, n - 1, n / 2, n - 1);
	} else {
		return ans(n / 2 - 1, n - 2, n / 2, n - 1);
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