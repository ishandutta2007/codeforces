#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, string> is;
typedef vector<is> vis;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m, a, b;
	string s;

	cin >> n >> m;
	vector<vis> v(m+1);
	for (int i = 0; i < n; i++) {
		cin >> s >> a >> b;
		v[a].emplace_back(b, s);
	}

	for (int i = 1; i <= m; i++) {
		vis &u = v[i];
		sort(u.begin(), u.end(), greater<is>());

		if (u.size() > 2 && u[1].fi == u[2].fi) {
			cout << "?" << endl;
		} else {
			cout << u[0].se << " " << u[1].se << endl;
		}

	}

	return 0;
}