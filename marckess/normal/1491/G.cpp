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
int n, a[MX], vis[MX];
vvi v;
vii res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		if (a[i] != i && !vis[i]) {
			vi w;
			int u = i;
			
			do {
				vis[u] = 1;
				w.pb(u);
				u = a[u];
			} while (u != i);
			
			v.pb(w);
		}
	
	for (int i = 0; i + 1 < (int)v.size(); i += 2) {
		vi &a = v[i];
		vi &b = v[i + 1];
		
		res.emplace_back(a.back(), b.back());
		
		for (int i = 0; i + 1 < (int)a.size(); i++)
			res.emplace_back(b.back(), a[i]);
			
		for (int i = 0; i + 1 < (int)b.size(); i++)
			res.emplace_back(a.back(), b[i]);
		
		res.emplace_back(a.back(), b.back());
	}
	
	if (v.size() & 1) {
		vi &a = v.back();
		int a3;
		
		if (a.size() == 2) {
			int a3 = 1;
			while (a3 == a[0] || a3 == a[1])
				a3++;
			res.emplace_back(a[0], a3);
			res.emplace_back(a[1], a3);
			res.emplace_back(a[0], a3);
		} else {
			for (int i = 1; i + 1 < (int)a.size(); i++)
				res.emplace_back(a[0], a[i]);
			res.emplace_back(a[1], a.back());
			res.emplace_back(a[0], a.back());
			res.emplace_back(a[0], a[1]);
		}
	}
	
	cout << res.size() << endl;
	for (auto &[a, b] : res)
		cout << a << " " << b << endl;
	
	return 0;
}