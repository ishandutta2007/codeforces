
// Problem : F. Defender of Childhood Dreams
// Contest : Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL : https://codeforces.com/contest/1586/problem/F
// Memory Limit : 512 MB
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

const int MX = 1005;
int n, k;
vi a[MX], to[MX];

void main_() {
	cin >> n >> k;
	
	a[n - 1] = {0};
	for (int i = n - 2; i >= 0; i--) {
		a[i] = a[i + 1];
		
		a[i][0]++;
		int carr = 0;
		
		for (int &x : a[i]) {
			x += carr;
			carr = x / k;
			x %= k;
		}
		
		if (carr)
			a[i].pb(carr);
		
		for (int j = i + 1; j < n; j++) {
			forn (k, a[i].size()) {
				if (a[j].size() == k)
					a[j].pb(0);
					
				if (a[j][k] + 1 <= a[i][k]) {
					to[i].pb(k);
					break;
				}
			}
		}
	}
	
	cout << a[0].size() << endl;
	forn (i, n)
		for (int x : to[i])
			cout << x + 1 << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}