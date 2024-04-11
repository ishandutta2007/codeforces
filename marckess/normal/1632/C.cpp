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


void main_() {
	int a, b;
	cin >> a >> b;
	
	int res = b - a;
	for (int x = a; x <= b; x++) {
		int y = 0;
		
		int f = 0;
		for (int i = 20; i >= 0; i--) {
			int n = x & (1 << i);
			int m = b & (1 << i);
			
			if (m) {
				if (!f || n)
					y |= 1 << i;
			} else {
				if (n) {
					f = 1;
					y |= 1 << i;
				}
			}
		}
		
		res = min(res, (x - a) + (y - b) + 1);
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}