
// Problem : D1. Gregor and the Odd Cows (Easy)
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/D1
// Memory Limit : 256 MB
// Time Limit : 6000 ms
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

const int MX = 6005;
int n;
map<ii, int> mp;
ll res;

ii operator - (const ii &a, const ii &b) {
	return {a.fi - b.fi, a.se - b.se};
} 

int operator ^ (const ii &a, const ii &b) {
	return a.fi * b.se - a.se * b.fi;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		mp[{x % 4, y % 4}]++;
	}
	
	for (auto it : mp)
		for (auto jt : mp)
			for (auto kt : mp) {
				auto ij = jt.fi - it.fi;
				auto ik = kt.fi - it.fi;
				auto jk = kt.fi - jt.fi;
				
				int area = ((ij ^ ik) / 2) % 2;
				int bord = ((abs(__gcd(ij.fi, ij.se)) + abs(__gcd(ik.fi, ik.se)) + abs(__gcd(jk.fi, jk.se))) / 2) % 2;
				
				if ((area + bord) % 2)
					continue;
				
				if (it == jt && it == kt) {
					res += 1ll * it.se * (jt.se - 1) * (kt.se - 2);
				} else if (it == jt) {
					res += 1ll * it.se * (jt.se - 1) * kt.se;
				} else if (it == kt) {
					res += 1ll * it.se * jt.se * (kt.se - 1);
				} else if (jt == kt) {
					res += 1ll * it.se * jt.se * (kt.se - 1);
				} else {
					res += 1ll * it.se * jt.se * kt.se;
				}
			}
	
	cout << res / 6 << endl;
	
	return 0;
}