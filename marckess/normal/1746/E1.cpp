#include <bits/stdc++.h>

// #define endl '\n'
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

vi operator + (vi a, vi b) {
	a.insert(a.end(), all(b));
	return a;
}

bool query (vi a) {
	cout << "? " << a.size();
	for (int x : a)
		cout << " " << x;
	cout << endl;
	
	string res;
	cin >> res;
	
	return res == "YES";
}

bool ans (int x) {
	cout << "! " << x << endl;
	
	string res;
	cin >> res;
	
	return res == ":)";
}

void main_() {
	int n;
	cin >> n;
	
	vi v(n);
	iota(all(v), 1);
	
	while (v.size() > 3) {
		vi a[4];
		
		forn (i, v.size())
			a[i % 4].pb(v[i]);
		
		int fi = query(a[0] + a[1]);
		int se = query(a[1] + a[2]);
		
		if (fi && se) {
			v = a[0] + a[1] + a[2];
		} else if (fi && !se) {
			v = a[0] + a[1] + a[3];
		} else if (!fi && se) {
			v = a[1] + a[2] + a[3];
		} else {
			v = a[0] + a[2] + a[3];
		}
 	}
 	
 	if (v.size() == 1) {
 		ans(v[0]);
 		return;
 	}
 	
 	if (v.size() == 2) {
 		if (!ans(v[0]))
 			ans(v[1]);
 		return;
 	}
 	
 	int fi = query({v[0], v[1]});
 	int se = query({v[1], v[2]});
 	
 	if (fi && se) {
		if (query({v[0]})) {
			if (!ans(v[0])) {
				if (query({v[1]})) {
					ans(v[1]);
				} else {
					ans(v[2]);
				}
			}
		} else {
			if (!ans(v[1]))
				ans(v[2]);
		}
	} else if (fi && !se) {
		if (!ans(v[0])) ans(v[1]);
	} else if (!fi && se) {
		if (!ans(v[1])) ans(v[2]);
	} else {
		if (!ans(v[0])) ans(v[2]);
	}
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}