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
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	map<int, ii> mp;
	int res = 0, last = -1;
	
	forn (i, n) {
		map<int, ii> nex;
		nex[a[i]] = {i, i};
		
		for (auto it : mp) {
			int g = __gcd(a[i], it.fi);
			
			if (nex.count(g)) {
				nex[g].fi = min(nex[g].fi, it.se.fi);
				nex[g].se = max(nex[g].se, it.se.se);
			} else {
				nex[g] = it.se;
			}
		}
		
		for (auto it : nex) {
			int l = it.se.fi;
			int r = it.se.se;
			int x = i - it.fi + 1;
			
			if (l <= x && x <= r)
				if (last < x) {
					res++;
					last = i;
				}
		}
		
		cout << res << " ";
		mp = nex;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
//	cin >> t;
	while (t--)
		main_();
	
	return 0;
}