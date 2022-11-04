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

const int MX = 200005;
int n, k, l[MX], r[MX];
vii ini[MX];
vi fin[MX];
set<ii, greater<ii>> st;
vi res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		ini[l[i]].emplace_back(r[i], i);
		fin[r[i]].push_back(i);
	}

	for (int i = 1; i < MX; i++) {
		for (ii &x : ini[i])
			st.emplace(x.fi, x.se);

		while (st.size() > k) {
			res.pb(st.begin()->se);
			st.erase(st.begin());
		}

		for (int x : fin[i])
			st.erase(ii(i, x));
	}

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}