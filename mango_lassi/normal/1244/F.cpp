#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// Calc what happens to interval in k steps
// Assuming string is BB WB ... WB WW (alternating for possibly odd length n)
string calc(int n, ll k) {
	char rc = (n % 2) ? 'B' : 'W';

	string res(n, '_');
	for (int i = 0; i < min((ll)n/2, k); ++i) res[i] = 'B';
	for (int i = k; i < n-k; ++i) res[i] = ((i-k)%2) ? 'B' : 'W';
	for (int i = max((ll)n/2, n-k); i < n; ++i) res[i] = rc;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll k;
	cin >> n >> k;
	string str;
	cin >> str;

	// Two back-to-back whites: Stay white
	// Two back-to-back blacks: Stay black
	// Compute for changing intervals, given endpoints
	string res(n, '_');
	for (int i = 0; i < n; ++i) {
		int ni = (i+1)%n;
		if (str[i] == str[ni]) {
			res[i] = str[i];
			res[ni] = str[ni];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (res[i%n] != '_') {
			int j = i+1;
			for (; j < 2*n; ++j) {
				if (res[j%n] != '_') break;
			}
			if (j-i > 1) {
				string rep = calc(j-i-1, k);
				if (str[(i+1)%n] == 'B') {
					for (char& c : rep) {
						if (c == 'B') c = 'W';
						else c = 'B';
					}
				}
				for (int t = i+1; t < j; ++t) {
					int ind = t-(i+1);
					res[t%n] = rep[ind];
				}
				i = j;
			}
		}
	}
	if (res[0] == '_') {
		int ini = (k & 1) + (str[0] == 'B');
		for (int i = 0; i < n; ++i) {
			if ((i + ini) % 2) res[i] = 'B';
			else res[i] = 'W';
		}
	}
	cout << res << '\n';
}