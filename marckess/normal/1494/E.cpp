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

const int MX = 200005;
int n, m;
map<ii, char> in;
map<ii, int> mp, lc[256];
int cn, cc;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	while (m--) {
		char op;
		cin >> op;
		
		if (op == '+') {
			int u, v;
			char c;
			cin >> u >> v >> c;
			
			in[ii(u, v)] = c;
			if (u > v) swap(u, v);
			
			if (++mp[ii(u, v)] == 2)
				cn++;
				
			if (++lc[c][ii(u, v)] == 2)
				cc++;
				
		} else if (op == '-') {
			int u, v;
			char c;
			
			cin >> u >> v;
			c = in[ii(u, v)];
			in.erase(ii(u, v));
			
			if (u > v) swap(u, v);
			
			if (mp[ii(u, v)]-- == 2)
				cn--;
			
			if (lc[c][ii(u, v)]-- == 2)
				cc--;
		} else {
			int k;
			cin >> k;
			
			if (k & 1) {
				if (cn) cout << "YES" << endl;
				else cout << "NO" << endl;
			} else {
				if (cc) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
	
	return 0;
}