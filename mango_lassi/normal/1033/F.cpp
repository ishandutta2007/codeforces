#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int W = 12;
const int CC = 1<<(2*W);
int cou[CC];
int dou[1<<W]; // doubles bits
int enc[1<<W]; // encodes a number

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, n, m;
	cin >> w >> n >> m;
	
	int cc = 1<<(2*w);
	for (int v = 0; v < (1<<w); ++v) {
		for (int j = 0; j < w; ++j) {
			if (v & (1<<j)) dou[v] |= (3<<(2*j));
			
			if (v & (1<<j)) enc[v] |= (2<<(2*j));
			else enc[v] |= (1<<(2*j));
		}
	}
	
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[enc[v]];
	}
	for (int code = 0; code < cc; ++code) {
		for (int j = 0; j < w; ++j) {
			int mask_a = 1 << (2*j);
			int mask_b = 2 << (2*j);
			int mask = mask_a | mask_b;
			if ((code & mask) == mask) {
				cou[code] = cou[code ^ mask_a] + cou[code ^ mask_b];
				break;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		reverse(str.begin(), str.end()); // big endian? seriously what a joke!

		// A: 00->11, 11->10: ^01, |10
		// O: 00->10, 11->00: ^10, &10
		// X: 00->10, 11->01: ^10
		// a: 00->00, 11->01: &01
		// o: 00->01, 11->11: |01
		// x: 00->01, 11->10: ^01
		
		int xor_mask = 0;
		int or_mask = 0;
		int and_mask = cc-1;
		for (int j = 0; j < w; ++j) {
			if (str[j] == 'A') {
				xor_mask ^= 2<<(2*j);
				or_mask  ^= 1<<(2*j);
			} else if (str[j]== 'O') {
				xor_mask ^= 1<<(2*j);
				and_mask ^= 2<<(2*j);
			} else if (str[j]== 'X') {
				xor_mask ^= 1<<(2*j);
			} else if (str[j]== 'a') {
				and_mask ^= 1<<(2*j);
			} else if (str[j]== 'o') {
				or_mask  ^= 2<<(2*j);
			} else if (str[j]== 'x') {
				xor_mask ^= 2<<(2*j);
			}
		}

		ll res = 0;
		for (int v = 0; v < (1<<w); ++v) {
			ll code = and_mask & (or_mask | (xor_mask ^ dou[v]));
			res += cou[code] * cou[enc[v]];
		}
		cout << res << '\n';
	}
}