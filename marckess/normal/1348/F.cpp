#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], b[MX], res[MX], ot[MX], f[MX];
vi pos[MX], del[MX];
set<ii> st;
set<int> in;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i] >> b[i];
		pos[a[i]].pb(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j : pos[i])
			st.emplace(b[j], j);

		f[i] = st.begin()->se;
		res[f[i]] = i;
		st.erase(st.begin());
	}

	for (int i = 1; i <= n; i++) {
		if (in.size() && *in.rbegin() >= a[f[i]]) {
			forn (i, n) ot[i] = res[i];
			swap(ot[f[i]], ot[f[*in.rbegin()]]);

			cout << "NO" << endl;
			
			forn (i, n) cout << res[i] << " ";
			cout << endl;

			forn (i, n) cout << ot[i] << " ";
			cout << endl;

			return 0;
		}

		in.insert(i);
		del[b[f[i]]].pb(i);

		for (int j : del[i])
			in.erase(j);
	}

	cout << "YES" << endl;
	forn (i, n) cout << res[i] << " ";
	cout << endl;

	return 0;
}