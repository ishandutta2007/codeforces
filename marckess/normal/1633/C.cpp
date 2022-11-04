
// Problem : C. Kill the Monster
// Contest : Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1633/problem/C
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

ll hc, dc, hm, dm, k, w, a;

ll techo (ll a, ll b) {
	return (a + b - 1) / b;
}

void main_() {
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	
	for (int i = 0; i <= k; i++) {
		ll x = techo(hm, dc + i * w);
		ll y = techo(hc + (k - i) * a, dm);
		
		if (x <= y) {
			cout << "YES" << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}