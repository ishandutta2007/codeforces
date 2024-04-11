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

int n, x;
set<int> st;
vi res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x;
	for (int i = 0; i < (1 << n); i++)
		st.insert(i);

	st.erase(0);
	st.erase(x);

	int acu = 0;
	while (st.size()) {
		int y = *st.begin();
		st.erase(y);
		st.erase(y ^ x);
		res.pb(acu ^ y);
		acu = y;
	}

	cout << res.size() << endl;
	for (int t : res)
		cout << t << " ";
	cout << endl;

	return 0;
}