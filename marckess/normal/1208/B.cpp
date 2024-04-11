#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, a[2005];
map<int, int> mp, aux;
set<int> st, par;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) {
		cin >> a[i];
		mp[a[i]]++;
		if (mp[a[i]] == 2) st.insert(a[i]);
	}

	if (st.empty()) {
		cout << 0 << endl;
		return 0;
	}

	int res = n;
	for (int i = 0; i < n; i++) {
		aux = mp;
		par = st;

		for (int j = i; j < n; j++) {
			aux[a[j]]--;
			if (aux[a[j]] == 1)
				par.erase(a[j]);
			if (par.empty()) {
				res = min(j - i + 1, res);
				break;
			}
		}
	}

	cout << res << endl;

	return 0;
}