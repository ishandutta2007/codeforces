
// Problem : G. Banquet Preparations 1
// Contest : Codeforces - Codeforces Round #753 (Div. 3)
// URL : https://codeforces.com/contest/1607/problem/G
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
int n, m, a[MX], b[MX], mn[MX], mx[MX], t[MX];

void main_() {
	cin >> n >> m;
	
	forn (i, n) {
		cin >> a[i] >> b[i];
		
		int d = min(m, a[i]);
		mn[i] = (a[i] - d) - (b[i] - (m - d));
		
		d = min(m, b[i]);
		mx[i] = (a[i] - (m - d)) - (b[i] - d);
	}
	
	ll res = 0;
	forn (i, n) {
		res += mn[i];
		t[i] = mn[i];
	}
	
	forn (i, n) {
		if (res >= 0) continue;
		
		int d = min(0ll + (mx[i] - mn[i]) / 2, -res / 2);
		
		res += 2 * d;
		t[i] = mn[i] + 2 * d; 
	}
	
	cout << abs(res) << endl;
	forn (i, n) {
		int d = -(t[i] - a[i] + b[i] - m) / 2;
		cout << d << " " << m - d << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}