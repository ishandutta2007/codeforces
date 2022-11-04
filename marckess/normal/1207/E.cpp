#include <bits/stdc++.h>
 
//#define endl '\n'
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	ll res = 0, r;
	string s = "?";
	for (ll i = 0, j = 0; i < 100; i++, j++)
		s += " " + to_string(j);
	cout << s << endl;
	cin >> r;
	for (int j = 7; j < 14; j++)
		res += (r & (1ll << j));

	s = "?";
	for (ll i = 0, j = (1 << 7); i < 100; i++, j += (1 << 7))
		s += " " + to_string(j);
	cout << s << endl;
	cin >> r;
	for (int j = 0; j < 7; j++)
		res += (r & (1 << j));

	cout << "! " << res << endl;

	return 0;
}