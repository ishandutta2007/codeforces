// Powered by CP Editor (https://cpeditor.org)

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
	int n;
	ii mn = {2e9, 2e9};
	ii mx = {-2e9, -2e9};
	ii ls = {-2e9, -2e9};
	
	cin >> n;
	while (n--) {
		int l, r, c;
		cin >> l >> r >> c;
		
		mn = min(mn, ii(l, c));
		mx = max(mx, ii(r, -c));
		ls = max(ls, ii(r - l + 1, -c));
		
		int d = mx.fi - mn.fi + 1;
		int x = mn.se - mx.se;
		int y = -ls.se;
		
		if (d > ls.fi) cout << x << endl;
		else if (d < ls.fi) cout << y << endl;
		else cout << min(x, y) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}