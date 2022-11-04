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

const int MX = 200005, SQ = 450;
int q, ex[MX];
ll x[MX], res[MX];
char op[MX];
vi pos[MX], in[MX];
map<ll, int> k, mp;

void main_() {
	cin >> q;
	
	ex[mp[0] = 0] = 1;
	
	forn (i, q) {
		cin >> op[i] >> x[i];
		
		if (op[i] == '+' || op[i] == '-') {
			if (!mp.count(x[i])) {
				int sz = mp.size();
				mp[x[i]] = sz;
			}
 		} else {
 			if (!k.count(x[i])) {
 				int sz = k.size();
 				k[x[i]] = sz;
 			}
 		}
	}
	
	for (auto it = k.begin(); it != k.end(); it++) {
		while (mp.count(it->fi * (ll)pos[it->se].size())) {
			int p = mp[it->fi * (ll)pos[it->se].size()];
			pos[it->se].pb(p);
		}
	}
	
	forn (i, q) {
		if (op[i] == '+' || op[i] == '-') {
			ex[mp[x[i]]] ^= 1;
		} else {
			int p = k[x[i]];
			
			if (pos[p].size() < SQ) {
				int f = 0;
				
				forn (j, pos[p].size()) {
					if (!ex[pos[p][j]]) {
						res[i] = x[i] * j;
						f = 1;
						break;
					}
				}
				
				if (!f) {
					res[i] = x[i] * ll(pos[p].size());
				}
			}
		}
	}
	
	for (auto it = k.begin(); it != k.end(); it++) {
		if (pos[it->se].size() >= SQ) {
			set<ll> st;
			forr (i, 1, pos[it->se].size())
				st.insert(i);
			
			forn (i, q) {
				if (op[i] == '+') {
					if (x[i] % it->fi == 0)
						st.erase(x[i] / it->fi);
				} else if (op[i] == '-') {
					if (x[i] % it->fi == 0)
						st.insert(x[i] / it->fi);
				} else if (x[i] == it->fi) {
					res[i] = it->fi * *st.begin();
				}
			}
		}
	}
	
	forn (i, q) {
		if (op[i] == '?')
			cout << res[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}