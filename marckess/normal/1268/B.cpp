#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 300005;
int n, a[MX], f, g;
ll res, off;
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		res += a[i] / 2;
	}
 
	for (int i = 0; i < n; i++) {
		if (a[i] % 2) {
			if (i % 2)
				f++;
			else
				g++;
		}
	}
 
	cout << res + min(f, g) << endl;
 
	return 0;
}