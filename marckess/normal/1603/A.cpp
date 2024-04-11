
// Problem : A. Di-visible Confusion
// Contest : Codeforces - Codeforces Round #752 (Div. 1)
// URL : https://codeforces.com/contest/1603/problem/A
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

const int MX = 100005;
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	int acu = 0;
	forn (i, n) {
		int k = 0;
		ll x = i + 2;
		
		while (a[i] % x == 0 && i + 2 - (k + 1) > 1) {
			k++;
			x = x * (i + 2 - k) / __gcd(x, 1ll * i + 2 - k);
		}
		
		if (k > acu || a[i] % x == 0) {
			cout << "NO" << endl;
			return;
		}
		acu++;
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}