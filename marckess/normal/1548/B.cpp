
// Problem : B. Integers Have Friends
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/B
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
int n;
ll a[MX], b[MX];
map<ll, int> mp;

void solve () {
	cin >> n;
	
	forn (i, n)
		cin >> a[i];
	
	forn (i, n - 1)
		b[i] = abs(a[i] - a[i + 1]);
	n--;
	
	int res = 1;
	mp.clear();
	
	forn (i, n) {
		map<ll, int> nex;
		
		if (b[i] > 1)
			nex[b[i]] = i;
		
		for (const auto& it : mp) {
			ll g = __gcd(it.fi, b[i]);
			
			if (g > 1) {
				if (!nex.count(g))
					nex[g] = it.se;
				else if (nex[g] > it.se)
					nex[g] = it.se;
			}
		}
		
		mp = nex;
		if (mp.size())
			res = max(res, i - mp.begin()->se + 2);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}