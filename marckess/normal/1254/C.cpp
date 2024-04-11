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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
ll in;
vii v;
vi a, b, res;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n;

	int j = 2;
	for (int i = 3; i <= n; i++) {
		cout << "2 1 " << j << " " << i << endl;
		cin >> in;
		if (in == -1)
			j = i;
	}

	for (int i = 2; i <= n; i++) {
		if (i != j) {
			cout << "1 1 " << j << " " << i << endl;
			cin >> in;
			v.emplace_back(in, i);
		}
	}

	sort(all(v));
	for (int i = 0; i + 1 < v.size(); i++) {
		cout << "2 1 " << v.back().se << " " << v[i].se << endl;
		cin >> in;
		if (in == -1) 
			a.pb(v[i].se);
		else
			b.pb(v[i].se);
	}
	reverse(all(b));

	res = {1, j};
	for (int x : a)
		res.pb(x);
	res.pb(v.back().se);
	for (int x : b)
		res.pb(x);

	cout << "0";
	for (int x : res)
		cout << " " << x;
	cout << endl;

	return 0;
}