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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		string s = to_string(i);
		string t = s;
		sort(all(s));
		sort(all(t));
		t.erase(unique(all(t)), t.end());
		if (s == t) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}