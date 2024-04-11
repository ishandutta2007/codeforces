#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;

const int N = 1 + (int)1e5;
const int V = 1 + 7000;
bool sf[V+1];
bitset<V> divs[V];
bitset<V> mults[V];
bitset<V> masks[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int v = V; v >= 2; --v) {
		sf[v] = true;
		int vv = v*v;
		for (int i = vv; i <= V; i += vv) sf[i] = false;
	}
	sf[1] = true;

	int n, q;
	cin >> n >> q;
	
	for (int v = 1; v <= V; ++v) {
		// divs[v][i] == 1 iff i | v
		for (int i = 1; i <= v; ++i) {
			if (v % i == 0) divs[v-1][i-1] = 1;
		}
		// mults[v][i] == [v|i] u(i/v)
		for (int i = v; i <= V; i += v) {
			if (sf[i / v]) mults[v-1][i-1] = 1;
		}
	}

	// Bit i: Is an even amount of numbers divisible by i? (1-indexed)
	// Join: xor
	// Product: and
	for (int j = 0; j < q; ++j) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, v;
			cin >> x >> v;
			--x; --v;
			masks[x] = divs[v];
		} else if (t == 2) {
			int x, y, z;
			cin >> x >> y >> z;
			--x; --y; --z;
			masks[x] = (masks[y] ^ masks[z]);
		} else if (t == 3) {
			int x, y, z;
			cin >> x >> y >> z;
			--x; --y; --z;
			masks[x] = (masks[y] & masks[z]);
		} else if (t == 4) {
			int x, v;
			cin >> x >> v;
			--x; --v;

			/*
			cout << x << ": ";
			for (int b = 0; b < 6; ++b) cout << masks[x][b]; cout << '\n';
			cout << "mask:" << v << ": ";
			for (int b = 0; b < 6; ++b) cout << mults[v][b]; cout << '\n';
			*/
			
			int cou = (masks[x] & mults[v]).count() % 2;
			cout << cou;	
		}
		/*
		for (int i = 0; i < n; ++i) {
			cout << i << ": ";
			for (int b = 0; b < 6; ++b) cout << masks[i][b]; cout << '\n';
		}
		*/
	}
	cout << '\n';
}