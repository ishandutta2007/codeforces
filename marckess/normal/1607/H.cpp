
// Problem : H. Banquet Preparations 2
// Contest : Codeforces - Codeforces Round #753 (Div. 3)
// URL : https://codeforces.com/contest/1607/problem/H
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
int n, a[MX], b[MX], m[MX], ra[MX], rb[MX];
map<int, vvi> mp;

void main_() {
	cin >> n;
	
	mp.clear();
	forn (i, n) {
		cin >> a[i] >> b[i] >> m[i];
		
		int mn = max(0, a[i] - m[i]);
		int mx = a[i] - max(0, m[i] - b[i]);
		
		mp[a[i] + b[i] - m[i]].pb({mn, mx, i});
	}
	
	int res = 0;
	for (auto &in : mp) {
		vvi &pos = in.se;
		
		sort(all(pos), [&] (const vi &a, const vi &b) {
			return a[1] < b[1];
		});
		
		int to = -1;
		for (vi &p : pos) {
			if (to < p[0]) {
				res++;
				to = p[1];
			}	
			
			ra[p[2]] = to;
			rb[p[2]] = in.fi - to;
		}
	}
	
	cout << res << endl;
	forn (i, n)
		cout << a[i] - ra[i] << " " << b[i] - rb[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}