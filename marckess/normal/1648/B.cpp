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

const int MX = 1000005;
int n, c, a[MX], cn[MX];

void main_() {
	cin >> n >> c;
	forn (i, c + 1)
		cn[i] = 0;
	
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
	}
	
	forr (i, 1, c)
		cn[i] += cn[i - 1];
	
	for (int y = 1; y <= c; y++) {
		if (cn[y] == cn[y - 1]) continue;
		
		for (int x = y, k = 1; x <= c; x += y, k++) {
			if (cn[k] != cn[k - 1]) continue;
			
			if (cn[min(x + y - 1, c)] != cn[x - 1]) {
				cout << "No" << endl;
				return;
			}
		}
	}
	
	cout << "Yes" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}