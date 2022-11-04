#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
int n, a[100005], mx = 0;
ll s = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) {
		cin >> a[i];
		s += a[i];
		mx = max(mx, a[i]);
	}

	if (s % 2 == 0 && 2 * mx <= s) cout << "YES" << endl;
	else cout << "NO" << endl;
 
	return 0;
}