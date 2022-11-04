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

const int MX = 100005;
int n, m, a[MX], b;
ll res;
set<int> st;

void solve () {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	res = 0;
	st.clear();
	for (int i = 0, j = 0; i < m; i++) {
		cin >> b;

		if (st.count(b)) {
			st.erase(b);
		} else {
			res += st.size();

			while (a[j] != b) {
				st.insert(a[j]);
				j++;
				res++;
			}
			
			j++;
		}
	}

	cout << 2 * res + m << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}