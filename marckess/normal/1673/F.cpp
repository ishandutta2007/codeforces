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

const int MX = 33;
int n, k, fil[MX], col[MX];

int cost (int a, int b, int i, int j) {
	int x = 0;
	
	while (b < j) {
		x ^= fil[b];
		b++;
	}
	while (b > j) {
		b--;
		x ^= fil[b];
	}
	while (a < i) {
		x ^= col[a];
		a++;
	}
	while (a > i) {
		a--;
		x ^= col[a];
	}
	
	return x;
}

void main_() {
	cin >> n >> k;
	
	for (int i = 1; i < n; i++) {
		int x = i;
		
		fil[i] = 0;
		while (x % 2 == 0) {
			fil[i]++;
			x /= 2;
		}
		
		col[i] = 1 << (2 * fil[i] + 1);
		fil[i] = 1 << (2 * fil[i]);
	}
	
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			cout << fil[j] << " ";
			c += fil[j];
		}
		cout << endl;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << col[i] << " ";
			c += col[i];
		}
		cout << endl;
	}
	
	int a = 1, b = 1;
	while (k--) {
		int x;
		cin >> x;
		
		for (int i = 1, f = 0; !f && i <= n; i++)
			for (int j = 1; !f && j <= n; j++)
				if (cost(a, b, i, j) == x) {
					cout << i << " " << j << endl;
					a = i;
					b = j;
					
					f = 1;
				}
	}
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}