// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 400010;
int n, l[MX], r[MX], ini[MX], fin[MX];
string s;

int find (vi &c, int x) {
	return lower_bound(all(c), x) - c.begin();
}

void main_() {
	cin >> n >> s;
	
	forn (i, s.size() + 1)
		l[i] = r[i] = -1;
	l[0] = r[0] = 0;
	
	int x = 0, y = 0;
	for (char c : s) {
		if (c == 'R') y++;
		else x++;
		
		if (l[x] == -1) l[x] = y;
		r[x] = y;
	}
	
	int m = x + 1, ver = n - 1 - x, hor = n - 1 - r[m - 1];
	
	vi c;
	for (int i = m - 1; i >= 0; i--) {
		c.pb(i);
		c.pb(i + ver * bool(i));
	}
	
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	
	int last = 0;
	forn (i, m) {
		int b = find(c, i + ver * bool(i));
		
		while (last <= b) {
			ini[last] = l[i];
			last++;
		}
	}
	
	last = (int)c.size() - 1;
	for (int i = m - 1; i >= 0; i--) {
		int a = i;
		
		while (last >= a) {
			fin[last] = r[i] + hor * bool(r[i]);
			last--;
		}
	}
	c.pb(c.back() + 1);
	
	ll res = 0;
	forn (i, (int)c.size() - 1)
		res += 1ll * (fin[i] - ini[i] + 1) * (c[i + 1] - c[i]);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}