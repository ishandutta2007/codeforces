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

int n, q, k;
map<ii, int> dp;

int query (int l, int r) {
	cout << "? " << l << " " << r << endl;
	int res;
	cin >> res;
	if (res == -1) exit(0);
	return res;
}

int query (int i, int j, int k) {
	if (i == j)
		return i;
	
	int m = (i + j) / 2;
	ii p(i, m);
	
	if (!dp.count(p))
		dp[p] = (m - i + 1) - query(i, m);
	
	int res;
	if (dp[p] >= k) {
		res = query(i, m, k);
		dp[p]--;
	} else {
		res = query(m + 1, j, k - dp[p]);
	}
	
	return res;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	while (q--) {
		int k;
		cin >> k;
		int res = query(1, n, k);
		cout << "! " << res << endl;
	}
		
	return 0;
}