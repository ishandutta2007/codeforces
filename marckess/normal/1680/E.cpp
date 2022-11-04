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

const int MX = 200010;
int n, l, r, mem[2][MX];
char c[2][MX];

int dp (int i, int j) {
	if (j == r) {
		if (c[1 - i][j] == '*')
			return 1;
		return 0;
	}
	
	int &res = mem[i][j];
	if (res != -1) return res;
	
	if (c[1 - i][j] == '*') {
		res = 2 + min(dp(0, j + 1), dp(1, j + 1));
	} else {
		res = min(1 + dp(i, j + 1), 2 + dp(1 - i, j + 1));
	}
	
	return res;
}

void main_() {
	cin >> n >> c[0] >> c[1];
	
	forr (i, 0, n)
		mem[0][i] = mem[1][i] = -1;
	
	l = r = -1;
	forn (i, n)
		if (c[0][i] == '*' || c[1][i] == '*') {
			if (l == -1) l = i;
			r = i;
		}
	
	if (l == r) {
		if (c[0][l] == c[1][l]) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}
	
	if (c[0][l] == c[1][l]) {
		cout << 2 + min(dp(0, l + 1), dp(1, l + 1)) << endl;
	} else if (c[0][l] == '*') {
		cout << 1 + dp(0, l + 1) << endl;
	} else {
		cout << 1 + dp(1, l + 1) << endl;
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