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

const int MX = 1000005, lim = 100;
int n;
string s;
vi c;

void print (string s) {
	int f = 0;
	for (char c : s) {
		if (c == '1')
			f = 1;
		if (f)
			cout << c;
	}
	if (!f) cout << 0 << endl;
	cout << endl;
}

void main_() {
	cin >> n >> s;
	int f = 0;
	
	forn (i, n) {
		if (s[i] == '0') {
			if (f) {
				c.pb(i);
			}
		} else {
			f = 1;
		}
	}
	
	if (!c.size()) {
		print(s);
		return;
	}
	
	string mx;
	int ind = -1;
	
	for (int i = c[0], j = 0; j < lim && i < n; i++, j++)
		mx.pb(s[i]);
	
	forn (k, c[0]) {
		string p;
		for (int i = c[0], j = 0; j < lim && i < n; i++, j++)
			p.pb('0' + (s[i] == '1' || s[k + j] == '1'));
		
		if (mx < p) {
			mx = p;
			ind = k;
		}
	}
	
	string ori = s;
	for (int i = c[0], j = 0; i < n; i++, j++)
		if (ori[ind + j] == '1')
			s[i] = '1';
	
	print(s);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}