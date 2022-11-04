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
	
	vi res;
	forn (kk, n) {
		int a;
		cin >> a;
		
		if (a == 1)
			res.pb(1);
		else {
			while (res.back() + 1 != a)
				res.pop_back();
			res.back()++;
		}
		
		forn (j, res.size()) {
			if (j) cout << ".";
			cout << res[j];
		}
		cout << endl;
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