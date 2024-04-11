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

const int MX = 200005;
int n;
string a, b;

void main_() {
	cin >> n >> a >> b;
	int x = 0, y = 0;
	
	forn (i, n) {
		if (a[i] == b[i]) x++;
		else y++;
	}
	
	if (x && y) {
		cout << "NO" << endl;
		return;
	}
	
	cout << "YES" << endl;
	vii res;
	
	int z = 0;
	
	forn (i, n) {
		if (a[i] == '0') {
			z++;
			res.pb({i, i});
		}
	}
	
	forn (i, n) {
		if (a[i] == '0') {
			if ((z - 1) % 2) {
				b[i] ^= 1;
			}
		} else {
			if (z % 2) {
				b[i] ^= 1;
			}
		}
	}
	
	if (b[0] == '0') {
		res.pb({0, n - 1});
	} else {
		res.pb({0, n - 2});
		res.pb({n - 1, n - 1});
	}
	
	cout << res.size() << endl;
	for (ii p : res)
		cout << p.fi + 1 << " " << p.se + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}