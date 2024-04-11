// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

int n;
string s, t;

#define no { cout << "NO" << endl; return; }

int count (vi &pos, int i, int j) {
	return upper_bound(all(pos), j) - lower_bound(all(pos), i);
}

void main_() {
	cin >> n >> s >> t;
	
	vvi ps(256), pt(256);
	
	forn (i, n) {
		ps[s[i]].pb(i);
		pt[t[i]].pb(i);
	}
	
	forn (i, 256)
		if (ps[i].size() != pt[i].size())
			no;
	
	forn (i, ps['a'].size()) {
		int x = ps['a'][i];
		int y = pt['a'][i];
		
		if (x > y) no;
		if (count(ps['c'], x, y) || count(pt['c'], x, y)) no;
	}
	
	forn (i, ps['c'].size()) {
		int x = ps['c'][i];
		int y = pt['c'][i];
		
		if (x < y) no;
		if (count(ps['a'], y, x) || count(pt['a'], y, x)) no;
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}