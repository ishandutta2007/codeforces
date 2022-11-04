
// Problem : A. Dislike of Threes
// Contest : Codeforces - Codeforces Round #739 (Div. 3)
// URL : https://codeforces.com/contest/1560/problem/A
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

int k;
vi a;

void solve () {
	cin >> k;
	cout << a[k - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int i = 1;
	while (a.size() < 1000) {
		if (i % 3 && i % 10 != 3)
			a.pb(i);
		i++;
	}
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}