#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 22;
int n, a[MX];

bool f() {
	int g = 0;
	forn (i, n)
		g = __gcd(g, a[i]);
	return g == 1;
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
		
	if (f()) {
		cout << 0 << endl;
		return;
	}
	
	int x = a[n - 1];
	a[n - 1] = __gcd(a[n - 1], n);
	if (f()) {
		cout << 1 << endl;
		return;
	}
	a[n - 1] = x;
	
	x = a[n - 2];
	a[n - 2] = __gcd(a[n - 2], n - 1);
	if (f()) {
		cout << 2 << endl;
		return;
	}
	
	cout << 3 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}