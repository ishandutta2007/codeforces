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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
set<ii> st;

void solve () {
	cin >> n;

	st.emplace(0, 0);
	st.emplace(1, 0);
	st.emplace(0, 1);
	st.emplace(1, 1);

	for (int i = 1; i <= n; i++) {
		st.emplace(i + 1, i + 1);
		st.emplace(i, i + 1);
		st.emplace(i + 1, i);
	}

	cout << st.size() << endl;
	for (ii r : st)
		cout << r.fi << " " << r.se << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}