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

const int MX = 100005;
int n;
vi a[MX], res[MX];
set<int> ex[MX];
map<int, map<int, int>> pos;

void main_() {
	cin >> n;
	forn (i, n) {
		int m;
		cin >> m;
		
		a[i].resize(m);
		res[i].resize(m);
		
		if (m % 2) {
			cout << "NO" << endl;
			return;
		}
		
		map<int, int> in;
		forn (j, m) {
			cin >> a[i][j];
			
			if (in.count(a[i][j])) {
				res[i][j] = 1;
				in.erase(a[i][j]);
			} else {
				in[a[i][j]] = j;
			}
		}
		
		for (const auto &it : in) {
			ex[i].insert(it.se);
			pos[it.fi][i] = it.se;
		}
	}

	for (const auto &it : pos)
		if (it.se.size() % 2) {
			cout << "NO" << endl;
			return;
		}
	
	int x = 0;
	while (x < n) {
		int i = x;
		
		while (ex[i].size()) {
			int u = a[i][*ex[i].begin()];
			res[i][*ex[i].begin()] = 1;
			
			ex[i].erase(ex[i].begin());
			pos[u].erase(i);
			
			int to = pos[u].begin()->fi;
			ex[to].erase(pos[u].begin()->se);
			pos[u].erase(pos[u].begin());
			
			i = to;
		}
		
		x++;
	}
	
	cout << "YES" << endl;
	forn (i, n) {
		for (int r : res[i])
			cout << "LR"[r];
		cout << endl;
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