// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

// #define endl '\n'
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

int query (int i, int j, int k) {
	cout << "? " << i << " " << j << " " << k << endl;
	int r;
	cin >> r;
	if (r == -1) exit(0);
	return r;
}

void ans (int i, int j) {
	cout << "! " << i << " " << j << endl;
}

void main_() {
	int n;
	cin >> n;
	
	int x, mx1 = -1;
	for (int i = 3; i <= n; i++) {
		int d = query(1, 2, i);
		if (d > mx1) {
			mx1 = d;
			x = i;
		}
	}
	
	int y, mx2 = -1;
	for (int i = 2; i <= n; i++) {
		if (i == x) continue;
		
		int d = query(1, x, i);
		if (d > mx2) {
			mx2 = d;
			y = i;
		}
	}

	int ot = 2;
	while (ot == x || ot == y)
		ot++;
	
	if (mx2 == query(1, x, ot)) ans(1, x);
	else if (mx2 == query(1, y, ot)) ans(1, y);
	else ans(x, y);
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}