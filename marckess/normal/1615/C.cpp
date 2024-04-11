// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
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
string a, b;

void main_() {
	cin >> n >> a >> b;
	
	int d = 0;
	forn (i, n)
		d += a[i] != b[i];
	
	int res = n + 1;
	
	if (d % 2 == 0) {
		int x = 0, y = 0;
		
		forn (i, n)
			if (a[i] != b[i]) {
				if (a[i] == '1') x++;
				else y++;
			}
			
		if (x == y || x == y + 1)
			res = min(res, x + y);
	}
	
	if ((n - d) % 2 == 1) {
		int x = 0, y = 0;
		
		forn (i, n)
			if (a[i] == b[i]) {
				if (a[i] == '1') x++;
				else y++;
			}
			
		if (x == y || x == y + 1)
			res = min(res, x + y);
	}
	
	if (res <= n) cout << res << endl;
	else cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}