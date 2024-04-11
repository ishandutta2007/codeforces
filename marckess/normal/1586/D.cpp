#include <bits/stdc++.h>

//#define endl '\n'
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

const int MX = 105;
int n, a[MX];

void main_() {
	cin >> n;
	
	for (int i = n; i > 1; i--) {
		cout << "?";
		forn (j, n - 1)
			cout << " " << 1;
		cout << " " << n + 2 - i << endl;
		cout << endl;
		
		int k;
		cin >> k;
		if (!k) {
			a[n] = i;
			break;
		}
	}
	
	if (!a[n]) a[n] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (i == a[n]) continue;
		
		cout << "?";
		forn (j, n - 1)
			cout << " " << (i < a[n] ? a[n] + 1 - i : a[n] + n - i);
		cout << " " << (i < a[n] ? 1 : n) << endl;
		cout << endl;
		
		int k;
		cin >> k;
		a[k] = i;
	}
	
	cout << "!";
	forn (i, n)
		cout << " " << max(1, a[i + 1]);
	cout << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}