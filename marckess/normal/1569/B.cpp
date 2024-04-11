
// Problem : B. Chess Tournament
// Contest : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1569/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int MX = 55;
int n;
char res[MX][MX];
string s;

void main_() {
	cin >> n >> s;
	
	forn (i, n)
		forn (j, n)
			res[i][j] = "=X"[i == j];
	
	vi v;
	forn (i, n)
		if (s[i] == '2')
			v.pb(i);
	
	if (v.size() == 1 || v.size() == 2) {
		cout << "NO" << endl;
		return;
	}
	
	forn (i, v.size()) {
		int x = v[i];
		int y = v[(i + 1) % v.size()];
		
		res[x][y] = '+';
		res[y][x] = '-';
	}
	
	cout << "YES" << endl;
	forn (i, n) {
		forn (j, n)
			cout << res[i][j];
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