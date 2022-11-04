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

const int MX = 1005;
int n, a[MX], b[MX], izq[MX], der[MX];

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n);
	
	set<int> pos;
	
	forn (i, n)
	forn (j, n) {
		pos.insert(a[i] + b[j]);
		if (a[i] + b[j] != abs(a[i] - b[j]))
			pos.insert(abs(a[i] - b[j]));
	}
	
	set<ii> da, db;
	forn (i, n) {
		da.insert({a[i], i});
		db.insert({b[i], i});
	}
	
	for (int x : pos) {
		int cn = 0;
		
		vii rba, rbb;
		
		while (da.size()) {
			if (da.rbegin()->fi > db.rbegin()->fi) {
				int ot = abs(da.rbegin()->fi - x);
				auto jt = db.lower_bound({ot, -1});
				
				if (jt == db.end() || jt->fi != ot)
					break;
					
				izq[da.rbegin()->se] = jt->se;
				der[jt->se] = da.rbegin()->se;
				
				rba.pb(*da.rbegin());
				rbb.pb(*jt);
				
				da.erase(*da.rbegin());
				db.erase(jt);
			} else {
				int ot = abs(db.rbegin()->fi - x);
				auto jt = da.lower_bound({ot, -1});
				
				if (jt == da.end() || jt->fi != ot)
					break;
				
				izq[jt->se] = db.rbegin()->se;
				der[db.rbegin()->se] = jt->se;
				
				rba.pb(*jt);
				rbb.pb(*db.rbegin());
				
				da.erase(jt);
				db.erase(*db.rbegin());
			}
			
			cn++;
		}
		
		if (cn == n) {
			cout << "YES" << endl;
			
			int p1 = 0, p2 = x, mn = 0;
			vi h;
			
			forn (u, n) {
				int v = izq[u];
				
				if (a[u] + b[v] == x) {
					h.pb(a[u]);
				} else if (a[u] < b[v]) {
					h.pb(-a[u]);
				} else {
					h.pb(p2 + b[v]);
				}
				
				mn = min(mn, h.back());
			}
			
			p1 -= mn;
			p2 -= mn;
			forn (i, n)
				h[i] -= mn;
			
			forn (i, n)
				cout << h[i] << " ";
			cout << endl;
			cout << p1 << " " << p2 << endl;
			
			return;
		} else {
			for (const auto& x : rba)
				da.insert(x);
				
			for (const auto& x : rbb)
				db.insert(x);
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