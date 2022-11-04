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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, m, com;
string s;
set<string> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) {
		cin >> s;
		st.insert(s);
	}
	forn (j, m) {
		cin >> s;
		if (st.count(s)) com++;
	}

	if (n > m) cout << "YES" << endl;
	else if (n < m) cout << "NO" << endl;
	else if (com % 2) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}