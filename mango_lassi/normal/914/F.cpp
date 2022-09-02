#include <iostream>
#include <string>
#include <bitset>
using namespace std;

const int N = 100000;
const int C = 26;
bitset<N> chars[C];
bitset<N> res;
bitset<N> one;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; ++i) {
		chars[str[i]-'a'][i] = 1;
	}
	for (int i = 0; i < N; ++i) one[i] = 1;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int i; char c;
			cin >> i >> c;
			--i;
			chars[str[i]-'a'][i] = 0;
			str[i] = c;
			chars[str[i]-'a'][i] = 1;
		} else {
			int l, r; string ptr;
			cin >> l >> r >> ptr;
			--l;
			int m = ptr.size();
			int s = r - l;
			if (s < m) {
				cout << "0\n";
			} else {
				res = one >> (N-(s-m+1));
				for (int i = 0; i < m; ++i) {
					res &= chars[ptr[i]-'a']>>(l+i);
				}
				cout << res.count() << '\n';
			}
		}
	}
}