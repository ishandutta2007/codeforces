
// Problem : C. Mocha and Hiking
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/C
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

const int MX = 10005;
int n, a[MX];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	if (a[1] == 1) {
		cout << n + 1 << " ";
		forn (i, n)
			cout << i + 1 << " ";
		cout << endl;
	} else if (a[n] == 0) {
		forn (i, n)
			cout << i + 1 << " ";
		cout << n + 1 << endl;
	} else {
		for (int i = 1;; i++)
			if (a[i] == 0 && a[i + 1] == 1) {
				for (int j = 1; j <= i; j++)
					cout << j << " ";
				cout << n + 1 << " ";
				for (int j = i + 1; j <= n; j++)
					cout << j << " ";
				cout << endl;
				break;
			}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}