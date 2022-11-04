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

int query (int l, int r) {
	cout << "? " << l << " " << r << endl;
	int res;
	cin >> res;
	if (res == -1) exit(0);
	return res;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	while (q--) {
		int k;
		cin >> k;
		
		int i = 1, j = n, rep = 20;
		
		while (rep--) {
			int m = (i + j) / 2;
			
			if (m - query(1, m) >= k) j = m;
			else i = m;
		}
		
		cout << "! " << j << endl;
	}
		
	return 0;
}