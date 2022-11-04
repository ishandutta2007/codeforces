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

const int MX = 1 << 16;
int n, k;

void main_() {
	cin >> n >> k;
	
	if (!k) {
		forn (i, n / 2)
			cout << i << " " << ((n - 1) ^ i) << endl;
		return;
	}
	
	if (k == n - 1) {
		if (n == 4) 
			cout << -1 << endl;
		else {
			cout << n - 2 << " " << n - 1 << endl;
			cout << 3 << " " << 1 << endl;
			cout << 0 << " " << (n - 4) << endl;
			cout << 2 << " " << n - 3 << endl;
			
			int i = 4, j = n - 5;
			while (i < j) {
				cout << i << " " << j << endl;
				i++, j--;
			}
		}
		return;
	}
	
	cout << k << " " << n - 1 << endl;
	cout << 0 << " " << ((n - 1) ^ k) << endl;
	
	forn (i, n / 2) {
		if (i)
		if (i != k)
		if (i != n - 1)
		if (i != ((n - 1) ^ k))
			cout << i << " " << ((n - 1) ^ i) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}