#include <bits/stdc++.h>

//#define endl '\n'
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

int query (int l, int r, int j) {
	cout << "? " << r - l + 1 << " " << 1 << endl;
	
	for (int i = l; i <= r; i++)
		cout << i << " ";
	cout << endl;
	
	cout << j << endl;
	
	int res;
	cin >> res;
	return res;
}

void solve () {
	cin >> n;
	
	int ind = 2;
	while (1) {
		if (query(1, ind - 1, ind))
			break;
		ind++;
	}
	
	int i = 1, j = ind - 1;
	while (i < j) {
		int m = (i + j) / 2;
		if (query(1, m, ind)) j = m;
		else i = m + 1;
	}
	
	set<int> res;
	for (int i = 1; i <= n; i++)
		res.insert(i);
	
	res.erase(j);
	res.erase(ind);
	
	for (int i = ind + 1; i <= n; i++)
		if (query(i, i, ind))
			res.erase(i);
	
	cout << "! " << res.size();
	for (int r : res)
		cout << " " << r;
	cout << endl;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}