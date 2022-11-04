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

const int MX = 5005;
int n, p[MX], acu[MX][MX];

void main_() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		
		for (int j = 1; j <= n; j++) {
			acu[i][j] = acu[i - 1][j];
			if (p[i] <= j)
				acu[i][j]++;
		}
	}
	
	ll res = 0;
	for (int b = 1; b <= n; b++)
		for (int c = b + 1; c <= n; c++) {
			ll x = acu[b - 1][p[c] - 1];
			ll y = acu[n][p[b] - 1] - acu[c][p[b] - 1];
			res += x * y;
		}
	
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