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

const int MX = 100005;
int n, q, acu[MX];
string s;

void solve () {
	cin >> n >> q >> s;
	forn (i, n) {
		acu[i] = s[i] - 'a' + 1;
		if (i)
			acu[i] += acu[i - 1];
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		
		if (l) cout << acu[r] - acu[l - 1] << endl;
		else cout << acu[r] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}