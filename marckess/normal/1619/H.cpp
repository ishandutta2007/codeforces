#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < int(n); i++)

using namespace std;

const int MX = 100005, SQ = 316;
int n, q, a[MX], b[MX], to[MX];

void update (int i) {
	to[i] = i;
	forn (j, SQ)
		to[i] = a[to[i]];
	
	int x = i, y = to[i];
	forn (j, SQ + 5) {
		to[x] = y;
		x = b[x];
		y = b[y];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		to[i] = i;
		forn (j, SQ)
			to[i] = a[to[i]];
	}
	
	while (q--) {
		int op, x, y;
		cin >> op >> x >> y;
		
		if (op == 1) {
			swap(a[x], a[y]);
			b[a[x]] = x;
			b[a[y]] = y;
			
			update(x);
			update(y);
		} else {
			while (y >= SQ) {
				x = to[x];
				y -= SQ;
			}
			
			while (y--) {
				x = a[x];
			}
			
			cout << x << '\n';
		}
	}
	
	return 0;
}