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

const int MX = 44;
int n, m, a[MX][MX];

void main_() {
	cin >> n >> m;
	forn (i, n)
	forn (j, m)
		cin >> a[i][j];
	
	int mx = a[0][0];
	forn (i, n)
	forn (j, m)
		mx = max(mx, a[i][j]);
	
	forn (i, n)
	forn (j, m)
		if (a[i][j] == mx) {
			cout << max(i + 1, n - i) * max(j + 1, m - j) << endl;
			return;
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