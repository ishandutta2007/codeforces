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

const int MX = 1005;
int n, m, a[MX][MX], mx[MX][MX], mn[MX][MX];

void main_() {
	cin >> n >> m;
	forn (i, n)
	forn (j, m) {
		cin >> a[i][j];
		mx[i][j] = -1e9;
		mn[i][j] = 1e9;
	}
	
	if ((n + m - 1) % 2) {
		cout << "NO" << endl;
		return;
	}
	
	int ned = (n + m - 1) / 2;
	
	mx[0][0] = a[0][0] < 0;
	mn[0][0] = a[0][0] < 0;
	
	forn (i, n)
	forn (j, m) {
		if (i + 1 < n) {
			mx[i + 1][j] = max(
				mx[i + 1][j],
				mx[i][j] + (a[i + 1][j] < 0)
			);
			mn[i + 1][j] = min(
				mn[i + 1][j],
				mn[i][j] + (a[i + 1][j] < 0)			
			);
		}
		
		if (j + 1 < m) {
			mx[i][j + 1] = max(
				mx[i][j + 1],
				mx[i][j] + (a[i][j + 1] < 0)
			);
			mn[i][j + 1] = min(
				mn[i][j + 1],
				mn[i][j] + (a[i][j + 1] < 0)			
			);
		}
	}
	
	if (mn[n - 1][m - 1] <= ned && ned <= mx[n - 1][m - 1])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}