
// Problem : B. Groups
// Contest : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1598/problem/B
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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

const int MX = 1005;
int n, a[MX][5];

void main_() {
	cin >> n;
	
	forn (i, n)
		forn (j, 5)
			cin >> a[i][j];
	
	if (n % 2) {
		cout << "NO" << endl;
		return;
	}
	
	forn (i, 5)
		forn (j, i) {
			int x = 0, y = 0;
			
			forn (k, n) {
				if (!a[k][i] && !a[k][j])
					x = y = n;
				
				x += a[k][i] && !a[k][j];
				y += a[k][j] && !a[k][i];
			}
			
			if (x <= n / 2 && y <= n / 2) {
				cout << "YES" << endl;
				return;
			}
		} 
	
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