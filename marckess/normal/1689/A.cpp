// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

int n, m, k;
string a, b, c;

void main_() {
	cin >> n >> m >> k >> a >> b;
	c.clear();
	
	sort(all(a));
	sort(all(b));
	
	int cn = 0, last = -1;
	while (a.size() && b.size()) {
		int nex = a[0] > b[0];
		
		if (nex == 0 && cn == k && last == 0) {
			nex = 1;
		}
		
		if (nex == 1 && cn == k && last == 1) {
			nex = 0;
		}
		
		if (nex == 0) {
			c.pb(a[0]);
			a = a.substr(1);
		} else {
			c.pb(b[0]);
			b = b.substr(1);
		}
		
		if (last != nex)
			cn = 0;
		
		last = nex;
		cn++;
	}
	
	cout << c << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}