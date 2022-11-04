#include <bits/stdc++.h>

// #define endl '\n'
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

const int MX = 10005;
int n, res[MX];

int query (int op, int i, int j, int x) {
	cout << "? " << op << " " << i << " " << j << " " << x << endl;
	int res;
	cin >> res;
	if (res == -1)
		exit(0);
	return res;
}

void solve () {
	cin >> n;
	if (n == -1)
		exit(0);
	
	int ind = -1;
	for (int i = 1; i + 1 <= n && ind == -1; i += 2) {
		int r = query(2, i, i + 1, 1);
		if (r == 1) {
			ind = i;
		} else if (r == 2) {
			r = query(2, i + 1, i, 1);
			if (r == 1)
				ind = i + 1;
		}
	}
	
	if (ind == -1)
		ind = n;
	
	res[ind] = 1;
	for (int i = 1; i <= n; i++)
		if (i != ind) {
			int r = query(1, ind, i, n - 1);
			res[i] = r;
		}
	
	cout << "!";
	for (int i = 1; i <= n; i++)
		cout << " " << res[i];
	cout << endl;
}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}