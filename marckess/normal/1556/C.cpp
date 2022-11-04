
// Problem : C. Compressed Bracket Sequence
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/C
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

const int MX = 1005;
int n;
ll a[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	unsigned long long res = 0;
	for (int i = 0; i < n; i += 2) {
		ll acu = 0, mn = 0;
		
		for (int j = i + 1; j < n; j++) {
			if (j % 2) {
				ll x = max(1ll, abs(mn));
				if (acu + x == 0) x++;
				
				ll y = min({
						a[i],
						x + a[j] - (acu + x)
				});
				
				if (x <= y)
					res += y - x + 1;
				
				acu -= a[j];
				mn = min(mn, acu);
			} else {
				acu += a[j];
			}
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	
	return 0;
}