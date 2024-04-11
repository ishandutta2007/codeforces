
// Problem : F. ATM and Students
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/F
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
int n, s, a[MX];

void main_() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	map<ll, int> mp;
	mp[1e18] = n + 2;
	mp[0] = n + 1;
	
	ll res = 0, acu = 0, l, r;
	
	for (int i = n; i > 0; i--) {
		acu += a[i];
		
		auto it = mp.upper_bound(acu + s);
		if (res < it->se - i - 1) {
			res = it->se - i - 1;
			l = i;
			r = it->se - 2;
		}
		
		while (mp.size() && mp.begin()->fi <= acu)
			mp.erase(mp.begin());
		mp[acu] = i;
	}
	
	if (res) cout << l << " " << r << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}