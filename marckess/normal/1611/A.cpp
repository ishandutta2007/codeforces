
// Problem : A. Make Even
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/A
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

void main_() {
	vi v;
	string s;
	
	cin >> s;
	for (char c : s)
		v.pb(c - '0');
	
	int f = 0;
	for (int x : v)
		if (x % 2 == 0)
			f = 1;
	
	if (!f) {
		cout << -1 << endl;
	} else if (v.back() % 2 == 0) {
		cout << 0 << endl;
	} else if (v[0] % 2 == 0) {
		cout << 1 << endl;
	} else {
		cout << 2 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}