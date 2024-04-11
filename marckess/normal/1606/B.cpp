
// Problem : B. Update Files
// Contest : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1606/problem/B
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

ll n, k;

void main_() {
	cin >> n >> k;
	n--;
	
	ll res = 0;
	forn (i, 1e9) {
		if (!n) break;
		
		ll x = 1;
		forn (kk, i)
			x *= 2;
		if (x >= k) break;
		
		n -= min(n, x);
		res++;
	}
	
	cout << res + (n + k - 1) / k << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}