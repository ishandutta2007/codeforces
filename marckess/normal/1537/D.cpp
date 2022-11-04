#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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

void solve () {
	cin >> n;
	
	if (n % 2) cout << "Bob" << endl;
	else {
		if (__builtin_popcount(n) == 1) {
			int cn = 0;
			
			while (n >= 1) {
				n /= 2;
				cn++;
			}
			
			if (cn % 2) cout << "Alice" << endl;
			else cout << "Bob" << endl;
		} else {
			cout << "Alice" << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}