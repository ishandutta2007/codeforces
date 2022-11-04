
// Problem : B. Xor of 3
// Contest : Codeforces - Codeforces Round #743 (Div. 1)
// URL : https://codeforces.com/contest/1572/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
		
	vi res;
	
	int cn = 0;
	forn (i, n) {
		if (a[i]) cn++;
		else if (i + 1 < n && a[i + 1] == 0 && cn % 2) {
			res.pb(i);
			a[i] = a[i + 1] = 1;
			cn++;
		}
	}
	
	cn = 0;
	forn (i, n) {
		if (a[i]) cn++;
		else if (0 < i && i + 1 < n && a[i - 1] && a[i + 1] && cn % 2) {
			res.pb(i);
			a[i - 1] = a[i + 1] = 0;
			cn--;
		}
	}
	
	forn (i, n) {
		if (i && i + 1 < n && !a[i - 1] && a[i] && a[i + 1]) {
			res.pb(i);
			a[i] = a[i + 1] = 0;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		if (i && i + 1 < n && a[i - 1] && a[i] && !a[i + 1]) {
			res.pb(i);
			a[i - 1] = a[i] = 0;
		}
	}
	
	forn (i, n)
		if (a[i]) {
			cout << "NO" << endl;
			return;
		}
	
	cout << "YES" << endl;
	cout << res.size() << endl;
	for (int r : res)
		cout << r << " ";
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