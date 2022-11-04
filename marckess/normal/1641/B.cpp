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

int n;
vi a;

void main_() {
	cin >> n;
	a = vi(n);
	
	map<int, int> mp;
	forn (i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	for (auto it : mp)
		if (it.se % 2) {
			cout << -1 << endl;
			return;
		}
	
	int off = 0;
	vii ins;
	vi res;
	
	while (a.size()) {
		if (a.size() == 1) {
			res.pb(2);
			a.clear();
		}
		
		int j = 1;
		while (a[j] != a[0])
			j++;
		res.pb(2 * j);
		
		vi b;
		for (int i = 1; i < j; i++)
			b.pb(a[i]);
		
		forn (i, b.size()) {
			ins.pb({j + i + 1 + off, b[i]});
		}
		off += res.back();
		
		reverse(all(b));
		for (int i = j + 1; i < a.size(); i++)
			b.pb(a[i]);
		
		a = b;
	}
	
	cout << ins.size() << endl;
	for (ii &r : ins)
		cout << r.fi << " " << r.se << endl;
	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}