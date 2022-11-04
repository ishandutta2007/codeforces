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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, p[MX];
set<ii> st;

void solve () {
	cin >> n;
	forn (i, n) {
		cin >> p[i];
		st.emplace(p[i], i);
	}
	while (st.size()) {
		int j = st.rbegin()->se;
		while (st.count(ii(p[j], j))) {
			cout << p[j] << " ";
			st.erase(ii(p[j], j));
			j++;
		}
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}