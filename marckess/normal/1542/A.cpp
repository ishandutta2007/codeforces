
// Problem : A. Odd Set
// Contest : Codeforces - Codeforces Round #729 (Div. 2)
// URL : https://codeforces.com/contest/1542/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
 
void solve () {
	int x = 0, y = 0;
	
	cin >> n;
	forn (i, 2 * n) {
		int a;
		cin >> a;
		if (a & 1) x++;
		else y++;
	}
	
	if (x == n) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}