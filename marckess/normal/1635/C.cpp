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

const int MX = 200005;
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	if (a[n - 2] > a[n - 1]) {
		cout << -1 << endl;
		return;
	}
	
	int rx = n - 2, ry = n - 1, rm = n - 1;
	ll mx = a[n - 1];
	ll suf = a[n - 2] - a[n - 1];
	
	for (int i = n - 3; i >= 0; i--) {
		if (a[i] > a[i + 1]) {
			if (suf > a[i + 1]) {
				cout << -1 << endl;
				return;
			}
			
			cout << i + 1 << endl;
			forn (j, i + 1)
				cout << j + 1 << " " << rx + 1 << " " << ry + 1 << endl;
			return;
		}
		
		if (a[i] - mx < suf) {
			suf = a[i] - mx;
			rx = i;
			ry = rm;
		}
		
		if (a[i] > mx) {
			mx = a[i];
			rm = i;
		}
	}
	
	cout << 0 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}