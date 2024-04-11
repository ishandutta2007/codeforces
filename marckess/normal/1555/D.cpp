
// Problem : D. Say No to Palindromes
// Contest : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1555/problem/D
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

const int MX = 200005;
int n, m, a[MX], acu[3][MX], b[MX], bcu[3][MX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		a[i] = b[i] = c - 'a';
		
		a[i] = MOD(a[i] - i, 3);
		b[i] = MOD(b[i] + i, 3);
		
		forn (j, 3) {
			acu[j][i] = acu[j][i - 1];
			bcu[j][i] = bcu[j][i - 1];
		}
		
		acu[a[i]][i]++;
		bcu[b[i]][i]++;
	}
	
	while (m--) {
		int l, r;
		cin >> l >> r;
		
		int res = 0;
		forn (i, 3) {
			res = max({
				res,
				acu[i][r] - acu[i][l - 1],
				bcu[i][r] - bcu[i][l - 1],
			});
		}
		
		cout << (r - l + 1) - res << endl;
	}
	
	return 0;
}