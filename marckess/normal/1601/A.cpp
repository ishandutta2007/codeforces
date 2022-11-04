
// Problem : A. Array Elimination
// Contest : Codeforces - Codeforces Round #751 (Div. 1)
// URL : https://codeforces.com/contest/1601/problem/A
// Memory Limit : 512 MB
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
int n, a[MX], cn[33];

void main_() {
	cin >> n;
	
	memset(cn, 0, sizeof(cn));
	forn (i, n) {
		cin >> a[i];
		
		forn (j, 30)
			cn[j] += bool(a[i] & (1 << j));
	}
	
	for (int i = 1; i <= n; i++) {
		int f = 1;
		
		forn (j, 30)
			f &= cn[j] % i == 0;
		
		if (f) cout << i << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}