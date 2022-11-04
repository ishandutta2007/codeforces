
// Problem : C. Ticks
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/C
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

const int MX = 22;
int n, m, k, vis[MX][MX];
char c[MX][MX];

void main_() {
	cin >> n >> m >> k;
	
	forn (i, n)
		forn (j, m)
			cin >> c[i][j];
	
	memset(vis, 0, sizeof(vis));
	
	for (int i = n - 1; i >= 0; i--)
		forn (j, m)
			if (c[i][j] == '*') {
				int d = 0;
				
				while (1) {
					if (i - d < 0 || j - d < 0 || j + d >= m) break;
					if (c[i - d][j - d] != '*' || c[i - d][j + d] != '*') break;
					d++;
				}
				d--;
				
				if (d >= k) {
					forn (h, d + 1) {
						vis[i - h][j - h] = 1;
						vis[i - h][j + h] = 1;
					}
				}
			}
	
	forn (i, n)
		forn (j, m)
			if (c[i][j] == '*' && !vis[i][j]) {
				cout << "NO" << endl;
				return;
			}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}