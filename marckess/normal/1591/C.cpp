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

const int MX = 200005;
int n, k, mx;
vi a, b;

void main_() {
	cin >> n >> k;
	
	mx = 0;
	a.clear();
	b.clear();
	
	forn (i, n) {
		int x;
		cin >> x;
		
		if (x < 0) a.pb(abs(x));
		else b.pb(abs(x));
		
		mx = max(mx, abs(x));
	}
	
	sort(all(a));
	sort(all(b));
	
	ll res = -mx;
	for (int i = int(a.size()) - 1; i >= 0; i -= k) res += 2 * a[i];
	for (int i = int(b.size()) - 1; i >= 0; i -= k) res += 2 * b[i];
	
	cout << res << endl;
		
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}