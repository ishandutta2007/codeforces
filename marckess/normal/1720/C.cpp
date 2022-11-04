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

const int MX = 505;
int n, m;
char c[MX][MX];

void main_() {
	cin >> n >> m;
	int cn = 0;
	
	forn (i, n)
	forn (j, m) {
		cin >> c[i][j];
		cn += c[i][j] == '1';
	}
	
	forn (i, n)
	forn (j, m) {
		if (c[i][j] == '1') continue;
		if (i + 1 < n && c[i + 1][j] == '0') {
			cout << cn << endl;
			return;
		}
		if (j + 1 < m && c[i][j + 1] == '0') {
			cout << cn << endl;
			return;
		}
		if (i + 1 < n && j + 1 < m && c[i + 1][j + 1] == '0') {
			cout << cn << endl;
			return;
		}
		if (i && j + 1 < m && c[i - 1][j + 1] == '0') {
			cout << cn << endl;
			return;
		}
		if (i + 1 < n && j && c[i + 1][j - 1] == '0') {
			cout << cn << endl;
			return;
		}
	}
	
	if (n * m == cn) cout << cn - 2 << endl;
	else cout << max(0, cn - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}