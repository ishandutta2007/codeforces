
// Problem : F. Array Stabilization (AND version)
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/F
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

const int MX = 1000005;
int n, d, a[MX];
vi pos[MX];

void main_() {
	cin >> n >> d;
	forn (i, n)
		cin >> a[i];
	
	forn (j, __gcd(n, d)) {
		pos[j].clear();
		
		int i = j;
		do {
			pos[j].pb(a[i]);
			(i += d) %= n;
		} while (i != j);
	}
	
	int res = 0;
	forn (j, __gcd(n, d)) {
		int f = 1;
		for (int x : pos[j])
			f = min(f, x);
		
		if (f) {
			cout << -1 << endl;
			return;
		}
		
		pos[j].insert(pos[j].end(), all(pos[j]));
		
		int cn = 0, mx = 0;
		for (int x : pos[j]) {
			if (x) cn++;
			else cn = 0;
			mx = max(mx, cn);
		}
		
		res = max(res, mx);
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