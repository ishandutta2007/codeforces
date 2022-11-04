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

const int MX = 100005;
int n, a[MX];

void main_() {
	cin >> n;
	
	ll s = 0, imp = 0;
	forn (i, n) {
		cin >> a[i];
		
		if (0 < i && i < n - 1) {
			s += a[i];
			imp += a[i] % 2;
		}
	}
	
	if (n == 3) {
		if (a[1] % 2) {
			cout << -1 << endl;
			return;
		}
	}
	
	if (n > 3) {
		int f = 0;
		for (int i = 1; i + 1 < n; i++)
			f += a[i] > 1;
		
		if (!f) {
			cout << -1 << endl;
			return;
		}
	}
	
	cout << (s + imp) / 2 << endl;
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}