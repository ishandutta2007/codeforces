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

int n, a, b, c;
string s;

ll go (int f) {
	vi v;
	int x = 0, cn = 0;
	ll acu = 0, res = 0;
	
	forn (i, n) {
		if (s[i] == '1') {
			if (!i || cn) {
				v.pb(cn);
				cn = 0;
			}
			
			if (i && s[i - 1] == '1')
				x++;
		} else {
			cn++;
		}
	}
	v.pb(cn);
	
	multiset<int> st;
	for (int i = 1; i + 1 < (int)v.size(); i++)
		st.insert(v[i]);
		
	while (1) {
		if (f) {
			if (x) {
				acu += b;
				x--;
			} else {
				break;
			}
		} else {
			int &y = v[0] > v.back() ? v[0] : v.back();
			auto it = st.lower_bound(2);
			
			if (x) {	
				if (it != st.end()) {
					acu += a;
					st.insert(*it - 1);
					st.erase(it);
				} else if (y >= 2) {
					acu += a;
					y--;
				} else if (st.size()) {
					acu -= c;
					st.erase(st.begin());
					x++;
				} else if (y == 1) {
					acu -= c;
					y--;
				} else {
					break;
				}
			} else {
				if (it != st.end() || y >= 2) {
					res = max(res, acu + a);
				}
				
				if (st.size() && *st.begin() == 1) {
					acu -= c;
					st.erase(st.begin());
					x++;
				} else {
					break;
				}
			}
		}
		
		res = max(res, acu);
		f ^= 1;
	}
	
	return res;
}

void main_() {
	cin >> n >> a >> b >> c >> s;
	cout << max(go(0), go(1)) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}