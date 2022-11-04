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
int n, a[MX], b[MX];
map<int, int> ma, mb;

void main_() {
	cin >> n;
	forn (i, n) cin >> b[i];
	forn (i, n) cin >> a[i];
	
	ma.clear();
	mb.clear();
	
	forn (i, n) {
		ma[a[i]]++;
		mb[b[i]]++;
	}
	
	ll res = 0;
	
	while (ma.size()) {
		int mx = max(ma.rbegin()->fi, mb.rbegin()->fi);
		
		if (ma.rbegin()->fi != mx)
			ma[mx] = 0;
		
		if (mb.rbegin()->fi != mx)
			mb[mx] = 0;
		
		auto &a = ma.rbegin()->se;
		auto &b = mb.rbegin()->se;
		
		if (a >= b) {
			res += a - b;
			
			if (a - b)
				ma[mx / 2] += a - b;
		} else {
			if (mx & 1) {
				cout << "NO" << endl;
				return;
			}
			
			res += b - a;
			mb[mx / 2] += b - a;
		}
		
		ma.erase(mx);
		mb.erase(mx);
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}