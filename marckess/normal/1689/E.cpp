// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 20005;
int n, a[MX], off;

bool esPos () {
	vi v;
	
	forn (i, n) {
		vi w = {a[i]};
		
		for (int x : v) {
			if (x & w[0]) {
				w[0] |= x;
			} else {
				w.pb(x);
			}
		}
		
		v = w;
	}
	
	return v.size() == 1;
}

void main_() {
	cin >> n;
	off = 0;
	forn (i, n) {
		cin >> a[i];
		
		if (!a[i]) {
			off++;
			a[i] = 1;
		}
	}
	
	if (esPos()) {
		cout << off << endl;
		forn (i, n)
			cout << a[i] << " ";
		cout << endl;
		return;
	}
	
	forn (i, n) {
		a[i]++;
		if (esPos()) {
			cout << off + 1 << endl;
			forn (i, n)
				cout << a[i] << " ";
			cout << endl;
			return; 
		}
		
		a[i] -= 2;
		if (esPos()) {
			cout << off + 1 << endl;
			forn (i, n)
				cout << a[i] << " ";
			cout << endl;
			return;
		}
		
		a[i]++;
	}
	
	int mx = -1;
	vi v;
	forn (i, n) {
		int b = 0;
		while (~a[i] & (1 << b))
			b++;
		
		if (b > mx) {
			mx = b;
			v = {i};
		} else if (b == mx) {
			v.pb(i);
		}
	}
	
	a[v[0]]++;
	a[v[1]]--;
	
	cout << off + 2 << endl;
	forn (i, n)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}