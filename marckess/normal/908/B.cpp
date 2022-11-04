#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
int n, m, x, y;
string s, a[55];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
int f[] = {0, 1, 2, 3};
 
int check (int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '#') return -1;
	if (a[i][j] == 'E') return 1;
	return 0; 
}
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) 
			if (a[i][j] == 'S')
				x = i, y = j;
	}
	cin >> s;
 
	int res = 0;
	do {
		int i = x, j = y;
		for (int c : s) {
			i += mx[f[c-'0']];
			j += my[f[c-'0']];
			int r = check(i, j);
			if (r == 1) {
				res ++;
				break;
			}
			if (r == -1) break;
		}
	} while (next_permutation(f, f+4));
 
	cout << res << endl;
 
	return 0;
}