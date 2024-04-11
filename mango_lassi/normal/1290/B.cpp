#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
const int C = 26;
int nxt[N][C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	for (int c = 0; c < C; ++c) nxt[n][c] = n;
	for (int i = n-1; i >= 0; --i) {
		for (int c = 0; c < C; ++c) nxt[i][c] = nxt[i+1][c];
		nxt[i][str[i] - 'a'] = i;
	}

	int q;
	cin >> q;

	// A string has an irreducible anagram iff at least one of the following holds
	//	1. The string is of length 1
	//	2. The first and last characters do not match
	//	3. The string contains at least three different characters
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		
		bool works = false;
		if (a == b) works = true;
		if (str[a] != str[b]) works = true;
		
		int cou = 0;
		for (int c = 0; c < C; ++c) {
			if (nxt[a][c] <= b) ++cou;
		}
		if (cou >= 3) works = true;

		if (works) cout << "Yes\n";
		else cout << "No\n";
	}
}