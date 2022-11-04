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

const int MX = 300;
int n, m, c[MX];
map<ii, int> mp;

vvi gaussJordan (vvi A, int mod) {
	if (!A.size()) return {};
	
	int n = A.size();
	int m = A[0].size();
	int i = 0, j = 0;
	
	while (j < m - 1) {
		int ind = i;
		while (ind < n && A[ind][j] == 0)
			ind++;
		
		if (ind == n) {
			j++;
			continue;
		}
		
		swap(A[i], A[ind]);
		
		int inv = A[i][j];
		for (int l = j; l < m; l++)
			A[i][l] = A[i][l] * inv % 3;
		
		for (int k = 0; k < n; k++) {
			if (k == i)
				continue;
			
			int fac = A[k][j];
			for (int l = j; l < m; l++) {
				A[k][l] = (A[k][l] - fac * A[i][l]) % 3;
				if (A[k][l] < 0)
					A[k][l] += 3;
			}
		}
		
		i++, j++;
	}
	
	return A;
}

void main_() {
	cin >> n >> m;
	
	mp.clear();
	forn (i, m) {
		int a, b;
		cin >> a >> b >> c[i];
		a--, b--;
		
		if (c[i] != -1)
			c[i]--;
		
		mp[{a, b}] = i;
		mp[{b, a}] = i;
	}
	
	vvi a;
	forn (k, n)
	forn (j, k)
	forn (i, j) {
		int acu = 0, p;
		vi ind;
		
		if (!mp.count({i, j})) continue;
		p = mp[{i, j}];
		if (c[p] == -1) ind.pb(p);
		else acu += c[p];
		
		if (!mp.count({i, k})) continue;
		p = mp[{i, k}];
		if (c[p] == -1) ind.pb(p);
		else acu += c[p];
		
		if (!mp.count({j, k})) continue;
		p = mp[{j, k}];
		if (c[p] == -1) ind.pb(p);
		else acu += c[p];
		
		if (ind.empty()) {
			if (acu % 3) {
				cout << -1 << endl;
				return;
			}
			continue;
		}
		
		vi v(m + 1);
		v[m] = MOD(-acu, 3);
		
		for (int x : ind)
			v[x] = 1;
		a.pb(v);
	}
	
	a = gaussJordan(a, 3);
	
	forn (i, a.size()) {
		int f = 0;
		
		forn (j, m) {
			if (a[i][j]) {
				f = 1;
				c[j] = a[i][m];
				break;
			}
		}
		
		if (!f && a[i][m]) {
			cout << -1 << endl;
			return;
		}
	}
	
	forn (i, m)
		if (c[i] < 0)
			c[i] = 0;
	
	forn (i, m)
		cout << c[i] + 1 << " ";
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