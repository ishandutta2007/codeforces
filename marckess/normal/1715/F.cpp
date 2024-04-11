#include <bits/stdc++.h>

// #define endl '\n'
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

const ld eps = 1e-6;
int n, m;

ld area (ld h, ld m) {
	ld b = (m - h) / m;
	return (m - h) * b / 2;
}

ld find (int n, int m, int swp) {
	cout << "? " << 2 * n + 1 << endl;
	
	forn (i, n) {
		ld a = 1.0l * i;
		ld b = 0.0l + bool(i) * eps * eps;
		ld c = 1.0l * i + 0.5l;
		ld d = 1.0l * m;
		
		if (swp) {
			swap(a, b);
			swap(c, d);
		}
		
		cout << a << " " << b << endl;
		cout << c << " " << d << endl;
	}
	
	ld a = 1.0l * n;
	ld b = 0.0l;
	
	if (swp) {
		swap(a, b);
	}
	
	cout << a << " " << b << endl;
	
	ld s;
	cin >> s;
	
	ld i = 0, j = m - 1, rep = 1000;
	while (rep--) {
		ld h = (i + j) / 2;
		
		ld z = area(h, m) - area(h + 1, m);
		
		if (z < s) j = h;
		else i = h;
	}
	
	return i;
}

void main_() {
	cin >> n >> m;
	
	ld y = find(n, m, 0);
	ld x = find(m, n, 1);
	
	cout << "! " << x << " " << y << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}