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

int n;
ll k;
string s;
set<int> st;

void solve () {
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			st.insert(i);

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			auto it = st.lower_bound(i);
			if (it != st.end() && *it - i <= k) {
				k -= *it - i;
				swap(s[i], s[*it]);
				st.erase(it);
			}
		}
		cout << s[i];
	}

	st.clear();
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int q;
	cin >> q;
	while (q--)
		solve();

	return 0;
}