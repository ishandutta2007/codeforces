
// Problem : D. Training Session
// Contest : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1598/problem/D
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
int n, a[MX], b[MX];
map<int, int> x, y;

void main_() {
	cin >> n;
	
	x.clear(), y.clear();
	
	forn (i, n) {
		cin >> a[i] >> b[i];
		
		x[a[i]]++, y[b[i]]++;
	}
	
	ll res = 0;
	
	forn (i, n)	
		res += 1ll * (x[a[i]] - 1) * (y[b[i]] - 1);
	
	res = 1ll * n * (n - 1) * (n - 2) / 6 - res;
	
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