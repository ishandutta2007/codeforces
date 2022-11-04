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

const int MX = 105;
int n, m;
string s[MX];

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> s[i];
	
	if (s[0][0] == '1') {
		cout << -1 << endl;
		return;
	}
	
	vvi res;
	for (int i = n - 1; i >= 0; i--)
	for (int j = m - 1; j >= 0; j--) {
		if (s[i][j] == '1') {
			if (j) {
				res.pb({i, j - 1, i, j});
			} else {
				res.pb({i - 1, j, i, j});
			}
		}
	}
	
	cout << res.size() << endl;
	for (vi v : res) {
		for (int x : v)
			cout << x + 1 << " ";
		cout << endl;
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