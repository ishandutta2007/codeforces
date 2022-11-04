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
	int a, b, c;
	cin >> a >> b >> c;
	
	int x = b - (c - b);
	if (x > 0 && x % a == 0) {
		cout << "YES" << endl;
		return;
	}
	
	if (a % 2 == c % 2) {
		x = (a + c) / 2;
		if (x > 0 && x % b == 0) {
			cout << "YES" << endl;
			return;
		}
	}
	
	x = b + (b - a);
	if (x > 0 && x % c == 0) {
		cout << "YES" << endl;
		return;
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}