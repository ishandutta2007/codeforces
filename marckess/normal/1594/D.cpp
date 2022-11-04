
// Problem : D. The Number of Imposters
// Contest : Codeforces - Codeforces Round #747 (Div. 2)
// URL : https://codeforces.com/contest/1594/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int n, m, p[MX], f[MX], rk[MX];

ii parent (int a) {
	int res = 0;
	
	while (a != p[a]) {
		res ^= f[a];
		a = p[a];
	}
	
	return {a, res};
}

bool join (int a, int b, int g) {
	ii x = parent(a);
	ii y = parent(b);
	
	if (x.fi == y.fi)
		return (x.se ^ g) == y.se;
	
	if (rk[x.fi] < rk[y.fi])
		swap(x, y);
	
	if (rk[x.fi] == rk[y.fi])
		rk[x.fi]++;
	
	p[y.fi] = x.fi;
	f[y.fi] = x.se ^ y.se ^ g;
	
	return 1;
}

void clear () {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		f[i] = 0;
		rk[i] = 0;
	}
}

void main_() {
	cin >> n >> m;
	
	clear();
	
	int f = 1;
	while (m--) {
		int u, v;
		string s;
		
		cin >> u >> v >> s;
		
		if (!join(u, v, s[0] == 'i'))
			f = 0;
	}
	
	if (!f) {
		cout << -1 << endl;
		return;
	}
	
	map<int, int> sz, mp;
	
	for (int i = 1; i <= n; i++) {
		ii a = parent(i);
		
		sz[a.fi]++;
		if (a.se)
			mp[a.fi]++;
	}
	
	int res = 0;
	for (auto it : sz)
		res += max(mp[it.fi], it.se - mp[it.fi]);
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