
// Problem : F2. Nearest Beautiful Number (hard version)
// Contest : Codeforces - Codeforces Round #739 (Div. 3)
// URL : https://codeforces.com/contest/1560/problem/F2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

string s;
int k;

int count (string s) {
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	return s.size();
}

void solve () {
	cin >> s >> k;
	
	string pre;
	set<char> st;
	
	forn (i, s.size()) {
		if (!st.count(s[i])) {
			if ((int)st.size() == k)
				break;
			st.insert(s[i]);
		}
		pre.pb(s[i]);
	}
	
	if (pre.size() == s.size()) {
		cout << pre << endl;
		return;
	}
	
	string res = pre;
	for (int i = pre.size(), f = 0; i < (int)s.size(); i++) {
		int g = 0;
		
		for (int d : st)
			if (f || d >= s[i]) {
				res.pb(d);
				f |= d > s[i];
				g = 1;
				break;
			}
		
		if (!g) {
			res.clear();
			break;
		}
	}
	
	if (res.size()) {
		cout << res << endl;
		return;
	}
	
	while (1) {
		int f = 0;
		
		while (pre.back() != '9') {
			pre.back()++;
			if (count(pre) <= k) {
				f = 1;
				break;
			}
		}
		
		if (f)
			break;
		pre.pop_back();
	}
	
	st.clear();
	for (char c : pre)
		st.insert(c);
	for (int i = '0'; (int)st.size() < k; i++)
		st.insert(i);
	
	res = pre;
	while (res.size() < s.size())
		res.pb(*st.begin());
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}