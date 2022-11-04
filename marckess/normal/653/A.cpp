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
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, a[55];
	cin >> n;
	forn(i, n) cin >> a[i];
	sort(a, a+n);
	unique(a, a+n);
	for(int i = 1; i + 1 < n; i++)
		if (a[i] == a[i-1] + 1 && a[i+1] == a[i] + 1) {
			cout << "YES" << endl;
			return 0;
		}

	cout << "NO" << endl;

	return 0;
}