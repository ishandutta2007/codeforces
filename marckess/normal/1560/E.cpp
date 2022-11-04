
// Problem : E. Polycarp and String Transformation
// Contest : Codeforces - Codeforces Round #739 (Div. 3)
// URL : https://codeforces.com/contest/1560/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string t;

void solve () {
	cin >> t;
	
	set<char> st;
	string ord;
	
	reverse(all(t));
	for (char c : t)
		if (!st.count(c)) {
			st.insert(c);
			ord.pb(c);
		}
	
	reverse(all(t));
	reverse(all(ord));
	
	map<char, int> cn;
	int sz = 0;
	
	for (char c : t)
		cn[c]++;
	
	forn (i, ord.size()) {
		if (cn[ord[i]] % (i + 1)) {
			cout << -1 << endl;
			return;
		}
		
		sz += cn[ord[i]] / (i + 1);
	}
	
	string s = t.substr(0, sz);
	
	string u, v = s;
	for (char c : ord) {
		u += v;
		
		string nex;
		for (char h : v)
			if (c != h)
				nex.pb(h);
		v = nex;
	}
	
	if (u == t) cout << s << " " << ord << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}