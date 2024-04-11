#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, m;
vi pos[256];
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		pos[s[i]].pb(i);
	}

	while (m--) {
		cin >> t;
		int res = 0, aux[256] = {0};
		for (char c : t)
			aux[c]++;
		for (int i = 'a'; i <= 'z'; i++)
			if (aux[i])
				res = max(res, pos[i][aux[i]-1]);
		cout << res+1 << endl;
	}
 
	return 0;
}