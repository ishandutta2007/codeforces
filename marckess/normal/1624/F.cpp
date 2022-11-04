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

int n;

void main_() {
	cin >> n;
	
	int i = 1, j = n;
	while (i < j) {
		int m = (i + j + 1) / 2;
		int r = n - m % n;
		
		if (r == n) {
			m--;
			r--;
		}
		
		cout << "+ " << r << endl;
		int q;
		cin >> q;
		
		if (m / n != q) i = m;
		else j = m - 1;
		
		i += r, j += r;
	}
	
	cout << "! " << i << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}